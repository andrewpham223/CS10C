#include "arithmeticExpression.h"

#include <fstream>
#include <sstream>
#include <stack>

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

// void arithmeticExpression::visualizeTree(const string &outputFilename){
//     ofstream outFS(outputFilename.c_str());
//     if(!outFS.is_open()){
//         cout<<"Error opening "<< outputFilename<<endl;
//         return;
//     }
//     outFS<<"digraph G {"<<endl;
//     visualizeTree(outFS,root);
//     outFS<<"}";
//     outFS.close();
//     string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
//     string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
//     system(command.c_str());
// }


arithmeticExpression::arithmeticExpression(const string &expr) : infixExpression(expr), root(nullptr) { }


void arithmeticExpression::buildTree() {
    string postFix = this->infix_to_postfix();
    stack<TreeNode*> treeStack;
    char newKey = 'a'; 
    for(unsigned i = 0; i < postFix.size(); ++i) {
        char c = postFix[i];
        if(c != '+' && c != '-' && c != '*' && c != '/') {
            TreeNode *newNode = new TreeNode(c, newKey);
            treeStack.push(newNode);
            newKey++;
        }
        else if(c == '+' || c == '-' || c == '*' || c == '*') {
            TreeNode *newNode = new TreeNode(c, newKey);

            newNode->right = treeStack.top();
            treeStack.pop();
            newNode->left = treeStack.top();
            treeStack.pop();
            treeStack.push(newNode);
            newKey++;
        }
        if(i == postFix.size()-1) {
            root = treeStack.top();
        } 
    }
}

void arithmeticExpression::infix() {
    infix(root);
}

void arithmeticExpression::prefix() {
    prefix(root);
}

void arithmeticExpression::postfix() {
    postfix(root);
}

void arithmeticExpression::infix(TreeNode *node) {
    if(node == nullptr) { return; }
    if(node->left) {
        cout << '(';
    }
    infix(node->left);
    cout << node->data;
    infix(node->right);
    if(node->left != nullptr) {
        cout << ')';
    }
}

void arithmeticExpression::prefix(TreeNode *node) {
    if(node == nullptr) { return; }
    cout << node->data;
    prefix(node->left);
    prefix(node->right);
}

void arithmeticExpression::postfix(TreeNode *node) {
    if(node == nullptr) { return; }
    postfix(node->left);
    postfix(node->right);
    cout << node->data;
}