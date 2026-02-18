#include <iostream>

#include "PyLongObject.h"

// constructors:
// default constructor
PyLongObject::PyLongObject(){
    sign = 1;
    numDigits = 0;
    fitsInLongLong = true;
    iValue = 0;
    digitsBase30 = nullptr;
}

// parameterized constructor
PyLongObject::PyLongObject(long long _iValue) {
    if (_iValue >= 0){
        sign = 1;
    }else{
        sign = -1;
    }
    
    numDigits = 0;
    fitsInLongLong = true;
    iValue = _iValue;
    digitsBase30 = nullptr;
}

// copy construct
PyLongObject::PyLongObject(const PyLongObject& other){
    sign = other.sign;
    numDigits = other.numDigits;
    fitsInLongLong = other.fitsInLongLong;
    iValue = other.iValue;

    if(fitsInLongLong){ // if true, no need to use base 30 (edge case)
        digitsBase30 = nullptr;
    }else{
        digitsBase30 = new unsigned[numDigits];
        for (int i = 0; i < numDigits; i++){
            digitsBase30[i] = other.digitsBase30[i];
        }
    }

}

// destructor
PyLongObject::~PyLongObject(){
    if (nullptr != digitsBase30) {
        delete[] digitsBase30;
    }
}


PyLongObject PyLongObject::operator+(const PyLongObject& other) const{
    // case 1 both x and y (x+y) are fit into long long
    // note: does not handle overflow if result exceeds long long
    if (fitsInLongLong && other.fitsInLongLong){
        long long result = iValue + other.iValue;
        return PyLongObject(result);
    }

    // case 2 both x and y are large numbers must be used in 2^30
    int maxDigits = 0;
    if (numDigits > other.numDigits){
        maxDigits = numDigits;
    }else{
        maxDigits = other.numDigits;
    }

    // +1 just for the carry over
    unsigned* resultDigits = new unsigned[maxDigits+1];
    unsigned carry = 0;
    for (int i = 0; i < maxDigits+1; i++){

        unsigned d1;
        if (i<numDigits){
            d1 = digitsBase30[i];
        }else{
            d1 = 0;
        }

        unsigned d2;
        if (i < other.numDigits) {
            d2 = other.digitsBase30[i];
        } else {
            d2 = 0;
        }

        unsigned sum = d1 + d2 + carry;
        resultDigits[i] = sum % (1 << 30);
        carry = sum / (1 << 30);
    }
    
    // checks if the last slot is 0 (we don't need to keep it)
    int resultNumDigits = maxDigits + 1;
    if (resultDigits[maxDigits] == 0) {
        resultNumDigits = maxDigits;
    }

    // result object
    PyLongObject result;
    result.sign = 1;
    result.fitsInLongLong = false;
    result.numDigits = resultNumDigits;
    result.digitsBase30 = new unsigned[resultNumDigits];
    // add the final result into the result object
    for (int i = 0; i < resultNumDigits; i++) {
        result.digitsBase30[i] = resultDigits[i];
    }

    // the cleanup & return
    delete[] resultDigits;
    return result;
}

// a func (didnt touch)
int PyLongObject::getDigitN(int n) const {  // returns -1 on failure
    if (n >+ numDigits && !fitsInLongLong) {
        return -1;
    } else {
        return digitsBase30[n];
    }
}

// a func (didnt touch)
long long PyLongObject::getSmallValue() {
    if (fitsInLongLong) {
        return iValue;
    } else {
        return -1;
    }
}

// Listing 2: A simple equalty check with an error! (didnt touch)
bool PyLongObject::operator==(const PyLongObject & other) const {
    if (this == &other) {
        return true;
    } else {
        if (fitsInLongLong != other.fitsInLongLong) return false;
        if (fitsInLongLong == other.fitsInLongLong && true == fitsInLongLong) {
            if (iValue == other.iValue) {
                return true;
            } else {
                return false;
            }
        }
        if (fitsInLongLong == other.fitsInLongLong && false == fitsInLongLong) {
            if (numDigits != other.numDigits) {
                return false;
            } else {
                for (int i = 0; i < numDigits; i++) {
                    if (getDigitN(i) != other.getDigitN(i)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

ostream & operator<<(ostream & os, const PyLongObject & pyLongObject) {
    if (pyLongObject.fitsInLongLong) {
        os << pyLongObject.iValue;
    } else {
        os << "Base2^30 digits: [";
        for (int i = pyLongObject.numDigits - 1; i >= 0; i--) {
            os << pyLongObject.digitsBase30[i];
            if (i > 0) {
                os << ", ";
            }
        }
        os << "]";
    }
    return os;
}