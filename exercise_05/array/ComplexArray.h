#ifndef _COMPLEX_ARRAY_H
#define _COMPLEX_ARRAY_H

#include <iostream>
#include "../number/ComplexNumber.h"

using namespace std;

class ComplexArray{
    ComplexNumber *complexArrayPtr;
    int numberOfComplexInstances;

    public:
        // our basic constructors - default, initialize, and copy constructor
        // the way we constructed out copy constructor is that it wont be allowed to be used - adding the syntax "= delete"
        ComplexArray(): complexArrayPtr(nullptr), numberOfComplexInstances{0} {}
        ComplexArray(int size) : complexArrayPtr(new ComplexNumber[size]), numberOfComplexInstances{size} {} // dynamic array of complex numbers
        ComplexArray(const ComplexArray & ComplexArray) = delete;

        // move constructor
        ComplexArray(ComplexArray && complexArray);
        // copy assignment operator
        ComplexArray & operator=(ComplexArray && complexArray);

        ~ComplexArray();

        int getSize();
        void put_complex_number(ComplexNumber & complexNumber, int position);
        ComplexNumber & get_complex_number(int position) const;

        friend ostream & operator<<(ostream & os, const ComplexArray & complexArray);
};

#endif