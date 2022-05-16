#include "Node.h"

#include <iostream>
using namespace std;

Node::Node(string s) : height(0), key(s), left(nullptr), right(nullptr), parent(nullptr) {}