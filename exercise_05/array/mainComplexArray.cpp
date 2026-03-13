#include <iostream>

#include "ComplexArray.h"

using namespace std;

int main(){
    int numComplex;
    cout << "How many complex numbers do you want?" << endl;
    cin >> numComplex;

    ComplexArray complexArr(numComplex);

    for (int i = 0; i < numComplex; i++){
        double real, imag;

        cout << "Enter real and imaginary for complex number " << i << ": " << endl;
        cin >> real >> imag;

        ComplexNumber temp(real, imag);
        complexArr.put_complex_number(temp, i);
    }


    cout << "Size of complex array: " << complexArr.getSize() << endl;

    cout << complexArr << endl;

    // second array created for the move operator
    cout << "Used move constructor: " << endl;
    ComplexArray secondComplexArr(std::move(complexArr)); // question to ask prof. when trying to compile i needed to use std:: why so? 


    cout << "Original Complex Array: \n" << complexArr << endl;
    cout << "Size of original: " << complexArr.getSize() << endl;

    cout << "Second Complex Array: \n" << secondComplexArr << endl;
    cout << "Size of moved array: " << secondComplexArr.getSize() << endl;


    return 0;
}