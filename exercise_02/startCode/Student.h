#ifndef _SIMPLE_STUDENT_H
#define _SIMPLE_STUDENT_H

#include <vector>
#include <string>

using namespace std;

struct Student {
    // by default these are public
    string name;
    int final;
    int midterm;
    vector<int> hw_grades;
};

// our declaration
Student get_student_struct_data();

ostream & operator<<(ostream & os, const Student & student);

#endif