#ifndef LIST_H_
#define LIST_H_

#include <iostream>
using namespace std;

struct Node {
    public:
        Node(int dataVal) : data(dataVal) { }
        int data;
        Node* next;
};

class List {
    private:
        Node* head;
        Node* tail;
    public:
        List(); // constructor
        ~List(); // destructor
        void print();
        void insert_front(int value);
        void insert_back(int value);
        void delete_first();
        void delete_last();
        Node* find_at_pos(int pos);
        void delete_at_pos(int pos);
        bool is_empty();
        void reverse();
        void remove_duplicates();
};

#endif
