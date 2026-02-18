#ifndef _PYLONGOBJECT_H
#define _YLONGOBJECT_H

#include <iostream>

using namespace std;

// code from the professor repo
// Listing 1: A surrogate for a CPython Integer
struct PyLongObject {
    // data members
    int sign; // +1 or -1.
    int numDigits;
    bool fitsInLongLong;

    long long iValue;
    
    unsigned *digitsBase30; // if too big, store as array of base 2^30 

    // constructors and others
    PyLongObject();
    PyLongObject(long long _iValue); // parameterized
    PyLongObject(const PyLongObject& other);
    ~PyLongObject();

    // functions
    int getDigitN(int n) const;  // returns -1 on failure
    long long getSmallValue();
    bool operator==(const PyLongObject & other) const;
    
};

#endif