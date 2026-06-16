#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

long long btree_ops = 0;

BTreeNode* btree_createNode(int t, int leaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->t = t;
    node->leaf = leaf;
    node->keys = (int*)malloc((2 * t - 1) * sizeof(int));
    node->C = (BTreeNode**)malloc((2 * t) * sizeof(BTreeNode*));
    node->n = 0;
    for (int i = 0; i < 2 * t; i++) node->C[i] = NULL;
    return node;
}

void btree_free(BTreeNode* root) {
    if (root != NULL) {
        if (!root->leaf) {
            for (int i = 0; i <= root->n; i++) {
                if (root->C[i]) btree_free(root->C[i]);
            }
        }
        free(root->keys);
        free(root->C);
        free(root);
    }
}

void btree_splitChild(BTreeNode* x, int i, BTreeNode* y, int t) {
    btree_ops++;
    BTreeNode* z = btree_createNode(t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++) z->keys[j] = y->keys[j + t];
    if (!y->leaf) {
        for (int j = 0; j < t; j++) z->C[j] = y->C[j + t];
    }
    y->n = t - 1;
    for (int j = x->n; j >= i + 1; j--) x->C[j + 1] = x->C[j];
    x->C[i + 1] = z;
    for (int j = x->n - 1; j >= i; j--) x->keys[j + 1] = x->keys[j];
    x->keys[i] = y->keys[t - 1];
    x->n = x->n + 1;
}

void btree_insertNonFull(BTreeNode* x, int k, int t) {
    int i = x->n - 1;
    btree_ops++;
    if (x->leaf) {
        while (i >= 0 && x->keys[i] > k) {
            btree_ops++;
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = k;
        x->n = x->n + 1;
    } else {
        while (i >= 0 && x->keys[i] > k) {
            btree_ops++;
            i--;
        }
        if (x->C[i + 1]->n == 2 * t - 1) {
            btree_splitChild(x, i + 1, x->C[i + 1], t);
            if (x->keys[i + 1] < k) i++;
        }
        btree_insertNonFull(x->C[i + 1], k, t);
    }
}

BTreeNode* btree_insert(BTreeNode* root, int k, int t) {
    if (root == NULL) {
        root = btree_createNode(t, 1);
        root->keys[0] = k;
        root->n = 1;
        return root;
    }
    if (root->n == 2 * t - 1) {
        BTreeNode* s = btree_createNode(t, 0);
        s->C[0] = root;
        btree_splitChild(s, 0, root, t);
        int i = 0;
        if (s->keys[0] < k) i++;
        btree_insertNonFull(s->C[i], k, t);
        return s;
    } else {
        btree_insertNonFull(root, k, t);
        return root;
    }
}

void btree_deleteRecursive(BTreeNode* x, int k, int t);

int btree_findKey(BTreeNode* x, int k) {
    int idx = 0;
    while (idx < x->n && x->keys[idx] < k) {
        btree_ops++;
        idx++;
    }
    return idx;
}

void btree_removeFromLeaf(BTreeNode* x, int idx) {
    for (int i = idx + 1; i < x->n; ++i) x->keys[i - 1] = x->keys[i];
    x->n--;
}

void btree_merge(BTreeNode* x, int idx, int t) {
    btree_ops++;
    BTreeNode* child = x->C[idx];
    BTreeNode* sibling = x->C[idx + 1];
    child->keys[t - 1] = x->keys[idx];
    for (int i = 0; i < sibling->n; ++i) child->keys[i + t] = sibling->keys[i];
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i) child->C[i + t] = sibling->C[i];
    }
    for (int i = idx + 1; i < x->n; ++i) x->keys[i - 1] = x->keys[i];
    for (int i = idx + 2; i <= x->n; ++i) x->C[i - 1] = x->C[i];
    child->n += sibling->n + 1;
    x->n--;
    free(sibling->keys);
    free(sibling->C);
    free(sibling);
}

void btree_borrowFromPrev(BTreeNode* x, int idx) {
    BTreeNode* child = x->C[idx];
    BTreeNode* sibling = x->C[idx - 1];
    for (int i = child->n - 1; i >= 0; --i) child->keys[i + 1] = child->keys[i];
    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i) child->C[i + 1] = child->C[i];
    }
    child->keys[0] = x->keys[idx - 1];
    if (!child->leaf) child->C[0] = sibling->C[sibling->n];
    x->keys[idx - 1] = sibling->keys[sibling->n - 1];
    child->n += 1;
    sibling->n -= 1;
}

void btree_borrowFromNext(BTreeNode* x, int idx) {
    BTreeNode* child = x->C[idx];
    BTreeNode* sibling = x->C[idx + 1];
    child->keys[child->n] = x->keys[idx];
    if (!child->leaf) child->C[child->n + 1] = sibling->C[0];
    x->keys[idx] = sibling->keys[0];
    for (int i = 1; i < sibling->n; ++i) sibling->keys[i - 1] = sibling->keys[i];
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i) sibling->C[i - 1] = sibling->C[i];
    }
    child->n += 1;
    sibling->n -= 1;
}

void btree_fill(BTreeNode* x, int idx, int t) {
    if (idx != 0 && x->C[idx - 1]->n >= t) btree_borrowFromPrev(x, idx);
    else if (idx != x->n && x->C[idx + 1]->n >= t) btree_borrowFromNext(x, idx);
    else {
        if (idx != x->n) btree_merge(x, idx, t);
        else btree_merge(x, idx - 1, t);
    }
}

int btree_getPred(BTreeNode* x, int idx) {
    BTreeNode* cur = x->C[idx];
    while (!cur->leaf) {
        btree_ops++;
        cur = cur->C[cur->n];
    }
    return cur->keys[cur->n - 1];
}

int btree_getSucc(BTreeNode* x, int idx) {
    BTreeNode* cur = x->C[idx + 1];
    while (!cur->leaf) {
        btree_ops++;
        cur = cur->C[0];
    }
    return cur->keys[0];
}

void btree_removeFromNonLeaf(BTreeNode* x, int idx, int t) {
    int k = x->keys[idx];
    btree_ops++;
    if (x->C[idx]->n >= t) {
        int pred = btree_getPred(x, idx);
        x->keys[idx] = pred;
        btree_deleteRecursive(x->C[idx], pred, t);
    } else if (x->C[idx + 1]->n >= t) {
        int succ = btree_getSucc(x, idx);
        x->keys[idx] = succ;
        btree_deleteRecursive(x->C[idx + 1], succ, t);
    } else {
        btree_merge(x, idx, t);
        btree_deleteRecursive(x->C[idx], k, t);
    }
}

void btree_deleteRecursive(BTreeNode* x, int k, int t) {
    int idx = btree_findKey(x, k);
    if (idx < x->n && x->keys[idx] == k) {
        if (x->leaf) btree_removeFromLeaf(x, idx);
        else btree_removeFromNonLeaf(x, idx, t);
    } else {
        if (x->leaf) return;
        int flag = ((idx == x->n) ? 1 : 0);
        if (x->C[idx]->n < t) btree_fill(x, idx, t);
        if (flag && idx > x->n) btree_deleteRecursive(x->C[idx - 1], k, t);
        else btree_deleteRecursive(x->C[idx], k, t);
    }
}

BTreeNode* btree_delete(BTreeNode* root, int k, int t) {
    if (!root) return NULL;
    btree_deleteRecursive(root, k, t);
    if (root->n == 0) {
        BTreeNode* tmp = root;
        if (root->leaf) root = NULL;
        else root = root->C[0];
        free(tmp->keys);
        free(tmp->C);
        free(tmp);
    }
    return root;
}
