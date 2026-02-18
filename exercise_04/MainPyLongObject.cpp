#include <iostream>
#include "PyLongObject.h"

using namespace std;

int main() {
    long long x, y;

    cout << "Enter first number: " << endl;
    cin >> x;

    cout << "Enter second number: " << endl;
    cin >> y;

    PyLongObject a(x);
    PyLongObject b(y);
    PyLongObject c = a + b;

    cout << "Result: " << endl;
    cout << c << endl;

    if (a == b){
        cout << "a and b are equal" << endl;
    }else{
        cout << "a and b are not equal" << endl;
    }

    return 0;
}