#include "AVLTree.h"
#include "Node.h"

#include <iostream>
#include <algorithm>
using namespace std;

int AVLTree::balanceFactor(Node *node) const {
    int lHeight = -1;
    int rHeight = -1;
    if(node->left) {
        lHeight = node->left->height;
    }
    if(node->right) {
        rHeight = node->right->height;
    }

    return lHeight - rHeight;
}

void AVLTree::updateHeight(Node *node) {
    int lHeight = -1;
    int rHeight = -1;
    if(node->left) {
        lHeight = node->left->height;
    }
    if(node->right) {
        rHeight = node->right->height;
    }

    node->height = max(lHeight, rHeight) + 1;    
}

bool AVLTree::setChild(Node *parent, string whichChild, Node *child) {
    if (whichChild != "left" && whichChild != "right") {
        return false;
    }
    if (whichChild == "left") {
        parent->left = child;
    }
    else {
        parent->right = child;
    }
    if (child) {
        child->parent = parent;
    }
    updateHeight(parent);
    return true;
}

bool AVLTree::replaceChild(Node *parent, Node *currentChild, Node *newChild)
{
    if (parent->left == currentChild) {
        return setChild(parent, "left", newChild);
    }
    else if (parent->right == currentChild) {
        return setChild(parent, "right", newChild);
    }
    return false;
}

void AVLTree::rotateRight(Node *node)
{
    Node* lrChild = node->left->right;
    if (node->parent)
    {
        replaceChild(node->parent, node, node->left);
    }
    else 
    {
        root = node->left;
        root->parent = nullptr;
    }

    setChild(node->left, "right", node);
    setChild(node, "left", lrChild);
}

void AVLTree::rotateLeft(Node *node)
{
    Node* rlChild = node->right->left;
    if (node->parent) {
        replaceChild(node->parent, node, node->right);
    }
    else {
        root = node->right;
        root->parent = nullptr;
    }

    setChild(node->right, "left", node);
    setChild(node, "right", rlChild);
}

void AVLTree::rebalance(Node *node) {
    updateHeight(node);

    if (balanceFactor(node) == -2) {
        if (balanceFactor(node->right) == 1) {
            rotateRight(node->right);
        }
        rotateLeft(node);
    }
    else if (balanceFactor(node) == 2) {
        if (balanceFactor(node->left) == -1) {
            rotateLeft(node->left);
        }
        rotateRight(node);
    }
}

void AVLTree::insert(const string &str) {
    Node* n = root;
    while (n) {
        if (n->key > str) {
            n = n->left;
        }
        else if (n->key < str) { 
            n = n->right;
        }
        else {
            return;
        }
    }

    Node* newNode = new Node(str);

    if (!root) {
        root = newNode;
        newNode->parent = nullptr;
        return;
    }

    Node* cur = root;
    while (cur) {
        if (newNode->key < cur->key) {
            if (!cur->left) {
                cur->left = newNode;
                newNode->parent = cur;
                cur = nullptr;
            }
            else {
                cur = cur->left;
            }
        }
        else {
            if (!cur->right) {
                cur->right = newNode;
                newNode->parent = cur;
                cur = nullptr;
            }
            else {
                cur = cur->right;
            }
        }
    }
    newNode = newNode->parent;

    while (newNode)
    {
        rebalance(newNode);
        newNode = newNode->parent;
    }
}
void AVLTree::printBalanceFactors() const {
    printBalanceFactors(root);
    cout << endl;
}

void AVLTree::printBalanceFactors(Node *node) const {
    if(node) {
        printBalanceFactors(node->left);
        cout << node->key << "(" << balanceFactor(node) << "), ";
        printBalanceFactors(node->right);
    }
}