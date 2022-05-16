#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
using namespace std;

struct Node {
    Node(string key);
    int height; 
    string key;
    Node* left;
    Node *right;
    Node* parent;
};


#endif