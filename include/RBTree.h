#ifndef RBTREE_H
#define RBTREE_H

#include "user.h"
#include <string>

enum Color { RED, BLACK };

struct RBNode {
    User data;
    Color color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

    RBNode(const User& u)
        : data(u), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree {
private:
    RBNode* root;
    RBNode* NIL;

    void leftRotate(RBNode* x);
    void rightRotate(RBNode* y);
    void insertFixup(RBNode* z);
    void transplant(RBNode* u, RBNode* v);
    RBNode* minimum(RBNode* node);

    void deleteNode(RBNode* z);
    void deleteFixup(RBNode* x);

    void printTree(RBNode* node, std::string indent, bool last);

public:
    RBTree();
    ~RBTree();
    void insert(const User& u);
    void remove(int userid);
    void printTree();
    void clear(RBNode* node);
};

#endif

