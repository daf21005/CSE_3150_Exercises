#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    int num_grades;
    int* grades;

    Student();
    Student(string _name, int _age, int _num_grades);
    Student(const Student& student);
    ~Student();

    void print() const;
};

#endif
