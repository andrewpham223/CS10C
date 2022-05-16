#include <iostream>
#include <vector>

using namespace std;

class tree_node {
    public:
        int value;
        tree_node *left;
        tree_node *right;
};

tree_node* newNode(int data) {
    tree_node *root = new tree_node();
    root->value = data;
    root->left = nullptr;
    root->right = nullptr;
    return root;
}

int height(tree_node *root) {
    if(root == nullptr) {
        return -1;
    }
    else {
        int heightLeftChild = height(root->left); 
        int heightRightChild = height(root->right); 
        
        if(heightLeftChild > heightRightChild) {
            return 1 + heightLeftChild;
        }
        else {
            return 1 + heightRightChild;
        }
    }
}

int sum(tree_node *root) {
    if(root == nullptr) {
        return 0;
    }
    else {
        return root->value + sum(root->left) + sum(root->right);
    }
}

bool search(tree_node *root, int key) {
    if(root == nullptr) { return false; }
    if(root->value == key) { return true; }
    return (search(root->left, key) || search(root->right, key));
}

//recursive helper function
int count_at_depth(tree_node *root, int currLevel, int target) {
    if(root == nullptr) {
        return 0;
    }
    if(currLevel == target) {
        return 1;
    }
    return count_at_depth(root->left, currLevel+1, target) + count_at_depth(root->right, currLevel+1, target);
}

/*creates vector using recursive helper to find the number of nodes at each level*/
vector<int> list_at_depth(tree_node *root) {
    vector<int> v;
    int treeHeight = height(root);
    for(int i = 0; i <= treeHeight; ++i) {
        v.push_back(count_at_depth(root, i, treeHeight));
        cout << v.at(i);
    }
    return v;
}

int main() {
    tree_node *myTree = newNode(15);
    myTree->left = newNode(31);
    myTree->right = newNode(251);
    myTree->right->left = newNode(18);
    myTree->right->right = newNode(100);
    myTree->right->right->right = newNode(69);
    cout << "Tree height: " << height(myTree) << endl;
    cout << "Sum of nodes: " << sum(myTree) << endl;
    cout << "Search for 420: " << search(myTree, 420) << endl;
    cout << "Number of nodes at each depth from 0 to the height: ";
    vector<int> v = list_at_depth(myTree);
    cout << endl;
}