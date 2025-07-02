#include "AVLTree.h"
#include <iostream>
#include <algorithm>

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(AVLNode* node) {
    return node ? node->height : 0;
}

int AVLTree::balanceFactor(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = 1 + std::max(height(y->left), height(y->right));
    x->height = 1 + std::max(height(x->left), height(x->right));
    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));
    return y;
}

AVLNode* AVLTree::balance(AVLNode* node) {
    node->height = 1 + std::max(height(node->left), height(node->right));
    int bf = balanceFactor(node);

    if (bf > 1 && balanceFactor(node->left) >= 0)
        return rotateRight(node);
    if (bf > 1 && balanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (bf < -1 && balanceFactor(node->right) <= 0)
        return rotateLeft(node);
    if (bf < -1 && balanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

AVLNode* AVLTree::insert(AVLNode* node, User data) {
    if (!node) return new AVLNode(data);
    if (data.userid < node->data.userid)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return balance(node);
}

AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

AVLNode* AVLTree::remove(AVLNode* node, int userid) {
    if (!node) return node;
    if (userid < node->data.userid)
        node->left = remove(node->left, userid);
    else if (userid > node->data.userid)
        node->right = remove(node->right, userid);
    else {
        if (!node->left || !node->right) {
            AVLNode* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        } else {
            AVLNode* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data.userid);
        }
    }
    return balance(node);
}

void AVLTree::printTree(AVLNode* node, std::string indent, bool last) {
    if (node) {
        std::cout << indent;
        if (last) {
            std::cout << "R----";
            indent += "     ";
        } else {
            std::cout << "L----";
            indent += "|    ";
        }
        std::cout << node->data.login << " (" << node->data.userid << ")\n";
        printTree(node->left, indent, false);
        printTree(node->right, indent, true);
    }
}

void AVLTree::insert(User data) {
    root = insert(root, data);
}

void AVLTree::remove(int userid) {
    root = remove(root, userid);
}

void AVLTree::printTree() {
    printTree(root, "", true);
}