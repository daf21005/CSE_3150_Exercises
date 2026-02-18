#include <iostream>

#include "Student.h"

using namespace std;

int main() {

    // something about polymorphic call?
    Student student = get_student_struct_data();

    cout << endl << student << endl;

    return 0;
}   

// g++ Student.cpp StudentMain.cpp
// ./a.out

// we compiled two source files linking them into one executable code