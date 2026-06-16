#ifndef AVL_H
#define AVL_H

typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode *left, *right;
} AVLNode;

extern long long avl_ops;

AVLNode* avl_insert(AVLNode* node, int key);
AVLNode* avl_delete(AVLNode* root, int key);
void avl_free(AVLNode* root);

#endif
