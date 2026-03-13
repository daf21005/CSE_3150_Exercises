#include "ComplexArray.h"
#include <iostream>

// constructors:
// move constructor - ComplexArray ca2(move(ca1)) 
ComplexArray::ComplexArray(ComplexArray && rightComplexArray){
    complexArrayPtr = rightComplexArray.complexArrayPtr;
    numberOfComplexInstances = rightComplexArray.numberOfComplexInstances;

    rightComplexArray.complexArrayPtr = nullptr;
    rightComplexArray.numberOfComplexInstances = 0;
}

// move operator
ComplexArray & ComplexArray::operator=(ComplexArray && rightComplexArray){
    // edge case - ensure the program doesn't crash when doing something like this a = a
    if (this == &rightComplexArray){
        return *this;
    }

    if (nullptr != complexArrayPtr){ // why nullptr to the right?
        delete [] complexArrayPtr;
    }

    complexArrayPtr = rightComplexArray.complexArrayPtr;
    numberOfComplexInstances = rightComplexArray.numberOfComplexInstances;

    rightComplexArray.complexArrayPtr = nullptr;
    rightComplexArray.numberOfComplexInstances = 0;

    return *this;
}

ComplexArray::~ComplexArray(){
    if (nullptr != complexArrayPtr) {
        delete [] complexArrayPtr;
    }
}

// methods:

int ComplexArray::getSize(){
    return numberOfComplexInstances;
}

// add and retrieve complex number
void ComplexArray::put_complex_number(ComplexNumber & complexNumber, int position){
    // edge case - ensure the given position is within the range of the array
    if (position >= 0 && position < numberOfComplexInstances){
        complexArrayPtr[position] = complexNumber;
    } else {
        cerr << "Error: position " << position << " is out of bounds" << endl;
        exit(1);
    }   
}

ComplexNumber & ComplexArray::get_complex_number(int position) const {
    // edge case - ensure the given position is within the range of the array
    if (position >= 0 && position < numberOfComplexInstances) {
        return complexArrayPtr[position];
    } else {
        cerr << "Error: position " << position << " is out of bounds" << endl;
        exit(1);
    }
}

ostream & operator<<(ostream & os, const ComplexArray & complexArray){
    for (int i = 0; i < complexArray.numberOfComplexInstances; i++){
        os << "Complex array of index  "
            << i 
            << ": " 
            << complexArray.get_complex_number(i)
            << endl;
    }
    return os;
}