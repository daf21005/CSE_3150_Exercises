#include "ComplexNumber.h"

// constructors:
ComplexNumber::ComplexNumber() : real{0.0}, imag{0.0} {}
ComplexNumber::ComplexNumber(double _real, double _img) : real(_real), imag(_img) { }
// copy constructor:
ComplexNumber::ComplexNumber(ComplexNumber & complex){
    real = complex.real;
    imag = complex.imag;
}

// our operators for complex number
ComplexNumber & ComplexNumber::operator=(const ComplexNumber & complex) {
    if(& complex == this){
        return *this;
    }else{
        real = complex.real;
        imag = complex.imag;
        return *this;   // since we are using a reference "&" we return the pointer this
    }
}

ComplexNumber & ComplexNumber::operator+=(const ComplexNumber & complex){
    real += complex.real;
    imag += complex.imag;

    return *this;
}

// methods:
double ComplexNumber::getReal() const { return real; }
double ComplexNumber::getImag() const { return imag; }

void ComplexNumber::setReal(double _real) { real = _real;}
void ComplexNumber::setImag(double _imag) { imag = _imag; }

// friend functions:
bool operator==(const ComplexNumber & left, const ComplexNumber & right){
    return (left.real == right.real && left.imag == right.imag);
}

bool operator!=(const ComplexNumber & left, const ComplexNumber & right){
    return !(left == right);
}

// this was changed where we dont have to use getReal but simply call real and imag 
ostream & operator<<(ostream & os, const ComplexNumber & complex){
    os << "real: "
        << complex.real
        << " imag: "
        << complex.imag;

    return os;
}