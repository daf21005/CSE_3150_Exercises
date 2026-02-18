#ifndef _PYLONGOBJECT_H
#define _YLONGOBJECT_H

#include <iostream>

using namespace std;

// code from the professor repo
struct PyLongObject {
    // data members
    int sign;               // +1 or -1.
    int numDigits;          // used for digitsBase30
    bool fitsInLongLong;    // T for normal long long, F for the number is too big
    long long iValue;       // the value it self
    // note to self, unsigned => x>=0
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
    // our addition
    PyLongObject operator+(const PyLongObject & other) const;
    
};

// stream output operator
ostream & operator<<(ostream & os, const PyLongObject & pyLongObject);

#endif