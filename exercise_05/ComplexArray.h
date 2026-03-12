#ifndef _COMPLEX_ARRAY_H
#define _COMPLEX_ARRAY_H

#include <iostream>
#include "ComplexNumber.h"

using namespace std;

class ComplexArray{
    ComplexNumber *complexArrayPtr;
    int numberOfCOmplexInstances;

    public:
        ComplexArray(): complexArrayPtr(nullptr), numberOfCOmplexInstances{0} {}
        ComplexArray(int size) : complexArrayPtr(new ComplexNumber[size]), numberOfCOmplexInstances{size} {}
        ComplexArray(const ComplexArray & ComplexArray) = delete;

        ComplexArray(ComplexArray && complexArray);
        ComplexArray & operator=(ComplexArray & ComplexArray);

        ~ComplexArray(); // {delete [] complexArrayPtr;}

        int getSize() {}

        void put_complex_number(ComplexNumber & complexNumber, int position);
        ComplexNumber & get_complex_number(int position) const;

        friend ostream & operator<<(ostream & os, const ComplexArray & complexArray);

};

#endif