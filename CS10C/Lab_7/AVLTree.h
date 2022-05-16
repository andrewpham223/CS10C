#ifndef _AVLTREE_H_
#define _AVLTREE_H_

#include "Node.h"
using namespace std;

class AVLTree {
    private:
        Node* root = nullptr;
    public:
        void insert(const string &str);
        int balanceFactor(Node *node) const;
        void printBalanceFactors() const;
    private:
        void updateHeight(Node* node);
        bool setChild(Node* parent, string whichChild, Node* child);
        bool replaceChild(Node* parent, Node* currentChild, Node* newChild);
        void rotateRight(Node* node);
        void rotateLeft(Node* node);
        void rebalance(Node* node);
        void printBalanceFactors(Node* node) const;
};

#endif