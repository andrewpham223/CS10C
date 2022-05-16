#include <iostream>
#include <stack>

using namespace std;

string InfixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    for(int i = 0; i <= infix.size()-1; ++i) {
        if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*')  {
            if(infix[i] == '+' || infix[i] == '-') {
                while(!s.empty() && (s.top() == '*' || s.top() == '/' || s.top() == '-' || s.top() == '+' ||  s.top() != '(')) {
                    postfix += s.top();
                    s.pop();
                }
            }
            s.push(infix[i]);
        }
        else if(infix[i] == '(') {
            s.push(infix[i]);
        }
        else if(infix[i] == ')') {
            while(!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            postfix += infix[i];
        }
    }
    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}


int PostfixEval(string postfix) {
}

int main() {
    string infix;
    cout << "Enter an infix expression: " << endl;
    getline(cin, infix);
    
    string postfix = InfixToPostfix(infix);
    cout << "Postfix conversion: " << postfix << endl;
    
    int postfixEval = PostfixEval(postfix);
    cout << postfix << " = " << postfixEval << endl; 

    return 0;
}