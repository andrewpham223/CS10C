#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList() {
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);

    dummyHead->prev = dummyTail;
    dummyHead->next = dummyTail;

    dummyTail->prev = dummyHead;
    dummyTail->next = dummyHead;
}

IntList::~IntList() {
    IntNode *currentNode = dummyHead;
    while(currentNode != dummyTail) {
        IntNode *tempNode = currentNode;
        currentNode = currentNode->next;
        delete tempNode;
    }
    delete currentNode;
}

void IntList::push_front(int value) {
    IntNode *newFront = new IntNode(value);
    IntNode *tempNode = dummyHead->next;
    newFront->prev = dummyHead;
    newFront->next = tempNode;
    tempNode->prev = newFront;
    dummyHead->next = newFront;
}

void IntList::pop_front() {
    if(!empty()) {
        IntNode *firstNode = dummyHead->next;
        dummyHead->next = firstNode->next;
        firstNode->next->prev = dummyHead;
        delete firstNode;
    }
}

void IntList::push_back(int value) {
    IntNode *newBack = new IntNode(value);
    IntNode *tempNode = dummyTail->prev;
    newBack->next = dummyTail;
    newBack->prev = tempNode;
    tempNode->next = newBack;
    dummyTail->prev = newBack;
}

void IntList::pop_back() {
    if(!empty()) {
        IntNode *lastNode = dummyTail->prev;
        dummyTail->prev = lastNode->prev;
        lastNode->prev->next = dummyTail;
        delete lastNode;
    }
}

bool IntList::empty() const {
    return (dummyHead->next == dummyTail && dummyHead->prev == dummyTail);
}

ostream & operator<<(ostream &out, const IntList &rhs) {
    if(!rhs.empty()) {
        IntNode *currentNode = rhs.dummyHead->next;
        while(currentNode != rhs.dummyTail) {
            out << currentNode->data;
            if(currentNode->next != rhs.dummyTail) {
                out << " ";
            }
            currentNode = currentNode->next;
        }
    }
    return out;
}

void IntList::printReverse() const {
    if(!empty()) {
        IntNode *currentNode = dummyTail->prev;
        while(currentNode != dummyHead) {
            cout << currentNode->data;
            if(currentNode->prev != dummyHead) {
                cout << " ";
            }
            currentNode = currentNode->prev; 
        }
    }
}




