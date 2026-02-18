#include <iostream>
#include "Student.h"
using namespace std;

int main() {
    cout << "--- Default constructor ---" << endl;
    Student s1;
    s1.print();

    cout << "\n--- Parameterized constructor ---" << endl;
    Student s2("Grace", 21, 3);
    s2.grades[0] = 95;   // direct access — public in struct
    s2.grades[1] = 88;
    s2.grades[2] = 92;
    s2.print();

    cout << "\n--- Copy constructor ---" << endl;
    Student s3 = s2;
    s3.print();

    // Prove deep copy works
    cout << "\n--- Changing s2's first grade to 50 ---" << endl;
    s2.grades[0] = 50;   // direct access again
    cout << "s2: "; s2.print();
    cout << "s3: "; s3.print();

    cout << "\n--- Heap allocation ---" << endl;
    Student* s4 = new Student("Ada", 20, 2);
    s4->grades[0] = 100;
    s4->print();
    delete s4;

    cout << "\n--- Stack objects destroyed here ---" << endl;
    return 0;
}
