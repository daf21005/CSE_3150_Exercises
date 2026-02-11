#include <iostream>
#include <vector>

#include "Student.h"
#include "LinkedList.h"

using namespace std;

// linked list main functionality within main
int main(){
    // initializes linked list as list
    LinkedList list;
    // start with an empty list
    // Node* head = nullptr;

    cout << "Entering Students data: " << endl;

    while (cin){
        // this creates a single Student struct variable
        Student student = get_student_struct_data();
        if (cin){
            // if input was succesful, add the copy of student into the linked list
            list.insert(student);

            // Node* newNode = new Node(student);
            // Add to linked list (insert at beginning)
            // newNode->next = head;
            // head = newNode;
        }
    }

    // Print all students
    list.print();
    // Node* current = head;
    // while (current != nullptr) {
    //     cout << current->data << endl;  // data is a Student
    //     current = current->next;
    // }

    // // destructor will take place
    // while (head != nullptr) {
    //     Node* temp = head;
    //     head = head->next;
    //     delete temp;
    // }
    return 0;
}