#include <iostream>

#include "ComplexArray.h"

using namespace std;

int main(){
    ComplexArray ca0(10), ca1(20), ca3(99);

    for (int i = 0; i<10; i++){
        ComplexNumber myComplex(static_cast<double>(i), static_cast<double>(i*2));
        ca0.put_complex_number(myComplex, i);
        
    }

    cout << "ca0 is: " << ca0 << endl;

    ComplexArray ca2(move(ca0));

    cout << "ca2: " << ca2 << endl;
    cout << "ca0 is: " << ca0 << endl;

    ca3 = move(ca1);



    return 0;
}