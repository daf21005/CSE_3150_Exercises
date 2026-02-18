#include <iostream>
#include "Student.h"

// ===== DEFAULT CONSTRUCTOR =====
// Called when you write: Student s;
Student::Student() {
    name = "Unknown";
    age = 0;
    grades = nullptr;
    num_grades = 0;
}

// ===== PARAMETERIZED CONSTRUCTOR =====
// Called when you write: Student s("Grace", 21, 3);
Student::Student(string _name, int _age, int _num_grades) {
    name = _name;
    age = _age;
    num_grades = _num_grades;

    // Allocate memory for grades
    if (num_grades > 0) {
        grades = new int[num_grades];
        for (int i = 0; i < num_grades; i++) {
            grades[i] = 0;
        }
    } else {
        grades = nullptr;  // No grades, no memory needed
    }
}

// ===== COPY CONSTRUCTOR =====
// Called when you write: Student s2 = s1;
// Deep copy — allocates new memory so they don't share
Student::Student(const Student& student) {
    name = student.name;
    age = student.age;
    num_grades = student.num_grades;

    if (student.grades != nullptr) {
        grades = new int[num_grades];
        for (int i = 0; i < num_grades; i++) {
            grades[i] = student.grades[i];
        }
    } else {
        grades = nullptr;
    }
}

// ===== DESTRUCTOR =====
// Called when the object goes out of scope or is deleted
Student::~Student() {
    cout << "Destructor called for " << name << endl;
    delete[] grades;
}

// ===== METHODS =====
// No getters/setters needed — fields are public in a struct
void Student::print() const {
    cout << "Name: " << name << ", Age: " << age << ", Grades: ";
    for (int i = 0; i < num_grades; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;
}
