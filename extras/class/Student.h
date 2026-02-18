#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>
using namespace std;

class Student {
    string name;
    int age;
    int num_grades;
    int* grades;

public:
    Student();
    Student(string _name, int _age, int _num_grades);
    Student(const Student& student);
    ~Student();

    string getName() const;
    int getAge() const;
    void setGrade(int index, int value);
    int getGrade(int index) const;
    void print() const;
};

#endif
