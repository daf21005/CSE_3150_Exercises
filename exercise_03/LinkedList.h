#ifndef NODE_H
#define NODE_H

#include "Student.h"

struct Node {
    Student data;
    struct Node* next;
    // struct Node* prev;

    Node(const Student& s) : data(s), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    int size;

    LinkedList();
    ~LinkedList();

    void insert(const Student& s);
    void print() const;
    bool isEmpty() const;
    int getSize() const;
};

#endif