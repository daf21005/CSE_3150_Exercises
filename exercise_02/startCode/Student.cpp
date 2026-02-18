#include <iostream>

#include "Student.h"

Student get_student_struct_data() {

    Student student;

    cout << "Enter name: " << endl;
    cin >> student.name;

    cout << "Enter midterm: " << endl;
    cin >> student.midterm;

    cout << "Enter final: " << endl;
    cin >> student.final;

    cout << "Enter a score or ^D for exit:  " << endl;
    int score;
    while (cin >> score) {
        student.hw_grades.push_back(score);
        cout << "Enter another score or ^D for exit: " << endl;
    }

    return student;
}

// what is this (do more research on this)
ostream & operator<<(ostream & os, const Student & student) {
    os << student.name
        << " Midterm: "
        << student.midterm
        << " Final: "
        << student.final
        << " homework scores: ";
        for (auto score : student.hw_grades){
            os << score
                << " ";
        }
    return os;
}