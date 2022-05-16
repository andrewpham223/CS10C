#include "List.h"

#include <iostream>
using namespace std;

List::List() {
    head = nullptr;
    tail = nullptr;
}

List::~List() {
    Node *curr = head;
    while(curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}

void List::print() {
    Node *curr = head;
    while(curr) {
        cout << curr->data;
        if(curr->next) {
            cout << " ";
        }
        curr = curr->next;
    }
    cout << endl;
}

void List::insert_front(int value) {
    Node *newNode = new Node(value);
    if(!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void List::insert_back(int value) {
    Node *tmp = new Node(value);
    tmp->next = nullptr;
    if(head == nullptr) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tmp;
    }
}

void List::delete_first() {
    if(head == NULL) return;
    Node *tmp = head;
    head = head->next;
    delete tmp;
}

void List::delete_last() {
    if(head == NULL) return;
    Node *curr = head;
    Node *prev;
    while( curr->next != NULL ) {
        prev = curr;
        curr = curr->next;
    }
    tail = prev;
    prev->next = NULL;
    delete curr;
}

Node* List::find_at_pos( int pos ) {
    Node* curr = head;
    int i = 0;
    while(curr != NULL) {
        if(pos == i) return curr;
        i++;
        curr = curr->next;
    }
    return NULL;
}

void List::delete_at_pos(int pos) {
    if(pos == 0) {
        delete_first();
        return;
    }
    Node *prev;
    Node *curr = head;
    for( int i = 0; i < pos; i++ ) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;
}

bool List::is_empty() {
    return (head == NULL);
}

void List::reverse() {
    Node *prevNode = nullptr;
    Node *currNode = head;
    Node *nextNode = nullptr;
    while(currNode != nullptr) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    Node *temp = head;
    head = tail;
    tail = temp;
}

void List::remove_duplicates() {
    Node *currNode = head;
    while(currNode != nullptr && currNode->next != nullptr) {
        if(currNode->data == currNode->next->data) {
            Node *nextNode = currNode->next;
            currNode->next = currNode->next->next;
            delete nextNode;
        }
        else {
            currNode = currNode->next;
        }
    }
    tail = currNode;
}