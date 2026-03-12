#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>

using namespace std;

class ComplexNumber{
    double real, imag;

    public:
        // constructors:
        ComplexNumber();
        ComplexNumber(ComplexNumber & complex);
        ComplexNumber(double _real, double _imag);

        // something
        ComplexNumber & operator=(const ComplexNumber & complex);
        ComplexNumber & operator+=(const ComplexNumber & complex);

        // methods:
        double getReal() const;
        double getImag() const;

        void setReal(double _real);
        void setImag(double _imag);

        // something:
        friend bool operator==(const ComplexNumber & left, const ComplexNumber & right);
        friend bool operator!=(const ComplexNumber & left, const ComplexNumber & right);
        friend ostream & operator<<(ostream & os, const ComplexNumber & complex); // moved inside of class - makes things slighlty easy
};

// the reason we have this here because it needs to understand what Complex is
// ostream & operator<<(ostream & os, const Complex & complex);

#endif