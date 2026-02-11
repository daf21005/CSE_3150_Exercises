#ifndef _SIMPLE_STUDENT_H
#define _SIMPLE_STUDENT_H

#include <vector>
#include <string>

// declaration file

using namespace std;

struct Student {

    // main attributes of a student
    string name;
    int final;
    int numHomeworks;
    int * hw_grades; // necassary for a dynamic allocated array

 
    // Constructors + Destructor
    Student();
    Student(string _name, int _final, int _number_of_homeworks);
    Student(const Student& student);
    Student& operator=(const Student& student);
    ~Student();
};

// function also declared
Student get_student_struct_data();

ostream & operator<<(ostream & os, const Student & student);

#endif