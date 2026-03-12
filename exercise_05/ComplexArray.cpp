#include "ComplexArray.h"
#include <iostream>

// {delete [] complexArrayPtr;}

// move constructor, this sets it up
ComplexArray::ComplexArray(ComplexArray && rightComplexArray){
    complexArrayPtr = rightComplexArray.complexArrayPtr;
    numberOfCOmplexInstances = rightComplexArray.numberOfCOmplexInstances;

    rightComplexArray.complexArrayPtr = nullptr;
    rightComplexArray.numberOfCOmplexInstances = 0;

}

// our assignment operator
ComplexArray & ComplexArray::operator=(ComplexArray & rightComplexArray){
    if (nullptr != complexArrayPtr){ // why nullptr to the right? - 
        delete [] complexArrayPtr;
    }

    complexArrayPtr = rightComplexArray.complexArrayPtr;
    numberOfCOmplexInstances = rightComplexArray.numberOfCOmplexInstances;


    rightComplexArray.complexArrayPtr = nullptr;
    rightComplexArray.numberOfCOmplexInstances = 0;


    return *this;
}

ComplexArray::~ComplexArray(){
    if (nullptr != complexArrayPtr) {
        delete [] complexArrayPtr;
    }

} // {delete [] complexArrayPtr;}

// add edge cases for both of the ones bellow:
void ComplexArray::put_complex_number(ComplexNumber & complexNumber, int position){
    complexArrayPtr[position] = complexNumber;

}

ComplexNumber & ComplexArray::get_complex_number(int position) const {
    return complexArrayPtr[position];
}

ostream & operator<<(ostream & os, const ComplexArray & complexArray){
    for (int i = 0; i < complexArray.numberOfCOmplexInstances; i++){
        os << complexArray.get_complex_number(i) << endl;
    }
    return os;
}