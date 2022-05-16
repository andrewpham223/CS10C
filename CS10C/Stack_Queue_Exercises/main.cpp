#include <iostream>
#include <stack>
#include <queue>

using namespace std;

template<typename T>
void stutter(queue<T> &Q) {
    queue<T> stutterQ;
    
    while(!Q.empty()) {
        stutterQ.push(Q.front());
        stutterQ.push(Q.front());
        Q.pop();
    }
    
    Q = stutterQ;

}

template<typename T>
void mirror(queue<T> &Q) {
    queue<T> mirrorQ = Q;
    stack<T> s;
    while(!Q.empty()) {
        s.push(Q.front());
        Q.pop();
    }
    while(!s.empty()) {
        mirrorQ.push(s.top());
        s.pop();
    }
    Q = mirrorQ;
}

int main() {
    queue<int> q;

    for(int i = 1; i <= 6; i++) {
        q.push(i);
    }
    mirror(q);
    for(int i = 1; i <= 12; i++) {
        cout << q.front();
        q.pop();
    }
}