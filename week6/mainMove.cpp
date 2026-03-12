#include <iostream>
#include <string>

using namespace std;

// using mighty move operator 3/4/26
int main(){
    string myName = "David";

    cout << myName << endl;
    cout << "----Move----" << endl;

    move(myName) = "Superman";

    cout << myName << endl;


    string s, t = "Great day!";

    cout << "s = " << s << endl;
    cout << "t = " << t << endl;

    cout << "----Move----" << endl;
    s = move(t);

    cout << "s = " << s << endl;
    cout << "t = " << t << endl;

    // the value of t was moved to s


    return 0;
}