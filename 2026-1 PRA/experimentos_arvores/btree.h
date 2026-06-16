#ifndef BTREE_H
#define BTREE_H

typedef struct BTreeNode {
    int *keys;
    int t;
    struct BTreeNode **C;
    int n;
    int leaf;
} BTreeNode;

extern long long btree_ops;

BTreeNode* btree_create(int t);
BTreeNode* btree_insert(BTreeNode* root, int k, int t);
BTreeNode* btree_delete(BTreeNode* root, int k, int t);
void btree_free(BTreeNode* root);

#endif
