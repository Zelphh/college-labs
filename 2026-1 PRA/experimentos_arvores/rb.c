#include <stdio.h>
#include <stdlib.h>
#include "rb.h"

long long rb_ops = 0;

RBNode* createRBNode(int key) {
    RBNode* node = (RBNode*)malloc(sizeof(RBNode));
    node->key = key;
    node->color = RED;
    node->left = node->right = node->parent = NULL;
    return node;
}

void rb_leftRotate(RBNode** root, RBNode* x) {
    rb_ops++;
    RBNode* y = x->right;
    if (y == NULL) return;
    x->right = y->left;
    if (y->left != NULL) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL) *root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rb_rightRotate(RBNode** root, RBNode* y) {
    rb_ops++;
    RBNode* x = y->left;
    if (x == NULL) return;
    y->left = x->right;
    if (x->right != NULL) x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL) *root = x;
    else if (y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}

void rb_insertFixup(RBNode** root, RBNode* z) {
    while (z->parent != NULL && z->parent->color == RED) {
        rb_ops++;
        if (z->parent->parent == NULL) break;
        if (z->parent == z->parent->parent->left) {
            RBNode* y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rb_leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rb_rightRotate(root, z->parent->parent);
            }
        } else {
            RBNode* y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rb_rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rb_leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

RBNode* rb_insert(RBNode* root, int key) {
    RBNode* z = createRBNode(key);
    RBNode* y = NULL;
    RBNode* x = root;

    while (x != NULL) {
        rb_ops++;
        y = x;
        if (z->key < x->key) x = x->left;
        else if (z->key > x->key) x = x->right;
        else { free(z); return root; }
    }
    z->parent = y;
    if (y == NULL) root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z;

    rb_insertFixup(&root, z);
    return root;
}

static void rb_transplant(RBNode** root, RBNode* u, RBNode* v) {
    if (u->parent == NULL) *root = v;
    else if (u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    if (v != NULL) v->parent = u->parent;
}

static RBNode* rb_minimum(RBNode* node) {
    while (node->left != NULL) {
        rb_ops++;
        node = node->left;
    }
    return node;
}

static void rb_deleteFixup(RBNode** root, RBNode* x, RBNode* x_parent) {
    while (x != *root && (x == NULL || x->color == BLACK)) {
        rb_ops++;
        if (x_parent == NULL) break;
        if (x == x_parent->left) {
            RBNode* w = x_parent->right;
            if (w != NULL && w->color == RED) {
                w->color = BLACK;
                x_parent->color = RED;
                rb_leftRotate(root, x_parent);
                w = x_parent->right;
            }
            if ((w == NULL) ||
                ((w->left  == NULL || w->left->color  == BLACK) &&
                 (w->right == NULL || w->right->color == BLACK))) {
                if (w != NULL) w->color = RED;
                x = x_parent;
                x_parent = x->parent;
            } else {
                if (w->right == NULL || w->right->color == BLACK) {
                    if (w->left != NULL) w->left->color = BLACK;
                    w->color = RED;
                    rb_rightRotate(root, w);
                    w = x_parent->right;
                }
                w->color = x_parent->color;
                x_parent->color = BLACK;
                if (w->right != NULL) w->right->color = BLACK;
                rb_leftRotate(root, x_parent);
                x = *root;
                x_parent = NULL;
            }
        } else {
            RBNode* w = x_parent->left;
            if (w != NULL && w->color == RED) {
                w->color = BLACK;
                x_parent->color = RED;
                rb_rightRotate(root, x_parent);
                w = x_parent->left;
            }
            if ((w == NULL) ||
                ((w->right == NULL || w->right->color == BLACK) &&
                 (w->left  == NULL || w->left->color  == BLACK))) {
                if (w != NULL) w->color = RED;
                x = x_parent;
                x_parent = x->parent;
            } else {
                if (w->left == NULL || w->left->color == BLACK) {
                    if (w->right != NULL) w->right->color = BLACK;
                    w->color = RED;
                    rb_leftRotate(root, w);
                    w = x_parent->left;
                }
                w->color = x_parent->color;
                x_parent->color = BLACK;
                if (w->left != NULL) w->left->color = BLACK;
                rb_rightRotate(root, x_parent);
                x = *root;
                x_parent = NULL;
            }
        }
    }
    if (x != NULL) x->color = BLACK;
}

RBNode* rb_delete(RBNode* root, int key) {
    RBNode* z = root;
    while (z != NULL) {
        rb_ops++;
        if (key == z->key) break;
        else if (key < z->key) z = z->left;
        else z = z->right;
    }
    if (z == NULL) return root;

    RBNode* y = z;
    Color y_original_color = y->color;
    RBNode* x;
    RBNode* x_parent;

    if (z->left == NULL) {
        x = z->right;
        x_parent = z->parent;
        rb_transplant(&root, z, z->right);
    } else if (z->right == NULL) {
        x = z->left;
        x_parent = z->parent;
        rb_transplant(&root, z, z->left);
    } else {
        y = rb_minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x_parent = y;
        } else {
            x_parent = y->parent;
            rb_transplant(&root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rb_transplant(&root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    free(z);

    if (y_original_color == BLACK)
        rb_deleteFixup(&root, x, x_parent);

    return root;
}

void rb_free(RBNode* root) {
    if (root != NULL) {
        rb_free(root->left);
        rb_free(root->right);
        free(root);
    }
}
