#include <iostream>
#include "Student.h"

// most of this is copy and pasted from prevoius exercise but did small changes

// Initialization constructor for homework array
Student::Student() {
    hw_grades = nullptr;
    numHomeworks = 0;
}

// assigning values to name, final, and number of homeworks
Student::Student(string _name, int _final, int _number_of_homeworks){
    name = _name;
    final = _final;
    numHomeworks = _number_of_homeworks;
    // Allocate memory for homework grades
    if (numHomeworks > 0) {
        hw_grades = new int[numHomeworks];
    } else {
        hw_grades = nullptr;  // No homeworks, no memory needed
    }

}

Student::Student(const Student& student){
    name = student.name;
    final = student.final;
    numHomeworks = student.numHomeworks;
    
    // Deep copy the array
    hw_grades = new int[numHomeworks];
    for (int i = 0; i < numHomeworks; i++) {
        hw_grades[i] = student.hw_grades[i];
    }

}

Student& Student::operator=(const Student& student){
    if (this != &student) {  // Check for self-assignment
        // Clean up old memory
        delete[] hw_grades;
        
        // Copy data
        name = student.name;
        final = student.final;
        numHomeworks = student.numHomeworks;
        
        // Deep copy the array
        hw_grades = new int[numHomeworks];
        for (int i = 0; i < numHomeworks; i++) {
            hw_grades[i] = student.hw_grades[i];
        }
    }
    return *this;
}

// Destructor to free up memory
Student::~Student() {
    if (nullptr != hw_grades) {
        delete[] hw_grades;
    }
}

// function that retrieves the data
Student get_student_struct_data(){
    // creates an empty Student struct
    Student student;

    string name;
    int final;
    int total_homeworks;

    // if (!cin) return student; were added to each input to handle ctrl+D 
    cout << "Enter student name (Ctrl+D to end): " << endl;
    cin >> student.name;
    if (!cin) return student;

    cout << "Enter student final: " << endl;
    cin >> student.final;
    if (!cin) return student;

    cout << "How many homeworks does the student have? " << endl;
    cin >> total_homeworks;
    if (!cin) return student;

    // negative, zero assignments or too assignments, return empty student
    if (total_homeworks <= 0 || total_homeworks >= 35){
        cout << "User either entered less than 1 assignments or too many assignments" << endl;
        return student; 
    } 
    student.numHomeworks = total_homeworks;
    student.hw_grades = new int[total_homeworks];       // Allocate memory for homework grades

    cout << "Enter a score:  " << endl;
    int score;
    for (int i = 0; i < student.numHomeworks; i++) {
        cin >> score;
        if (!cin) {
            return student;
        }
        student.hw_grades[i] = score;
        // This block just makes the prompt cleaner (nothing too complex)
        if (i < student.numHomeworks - 1){
            cout << "Enter another score: " << endl;
        }
        
    }

    return student;
}



ostream & operator<<(ostream & os, const Student & student) {
    os << student.name
        << " Final: "
        << student.final
        << " Homework scores: ";
        for (int i = 0; i < student.numHomeworks; i++){
            os << student.hw_grades[i]
                << " ";
        }
    return os;
}