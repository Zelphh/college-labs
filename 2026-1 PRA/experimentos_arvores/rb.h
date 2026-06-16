#ifndef RB_H
#define RB_H

typedef enum { RED, BLACK } Color;

typedef struct RBNode {
    int key;
    Color color;
    struct RBNode *left, *right, *parent;
} RBNode;

extern long long rb_ops;

RBNode* rb_insert(RBNode* root, int key);
RBNode* rb_delete(RBNode* root, int key);
void rb_free(RBNode* root);

#endif
