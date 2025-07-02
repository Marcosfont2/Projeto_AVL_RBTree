#ifndef AVLTREE_H
#define AVLTREE_H

#include "user.h"

struct AVLNode {
    User data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(User u) : data(u), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* balance(AVLNode* node);
    AVLNode* insert(AVLNode* node, User data);
    AVLNode* minValueNode(AVLNode* node);
    AVLNode* remove(AVLNode* node, int userid);
    void printTree(AVLNode* node, std::string indent, bool last);

public:
    AVLTree();
    void insert(User data);
    void remove(int userid);
    void printTree();
};

#endif


