#include <iostream>
#include "LinkedList.h"

// initialize
LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

// destructor
LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// used to print the students
void LinkedList::print() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}

// the "common functions" for linked list
void LinkedList::insert(const Student& s) {
    Node* newNode = new Node(s);
    newNode->next = head;
    head = newNode;
    size++;
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

int LinkedList::getSize() const {
    return size;
}