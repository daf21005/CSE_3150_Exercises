# CSE 3150 - Exercise 5 C++ Move Exercise
This exercise expands on what we created within our lecture with Complex Numbers (real and imaginary).  
For this exercise we are implementing Complex Array where we dynammacilly allocated array of ComplexNumber instances.  

For this assignment, the copy constructor wont work. The only way to pass the values around is the move constructor or move operator.  
Note to self: When trying to compile the program, to use move() we must include std:: even though we have "using namespace std;" at the top. Search more on this.   

## Compile and Run main program (before running this make sure you are in the directory that can access all folders)
```
g++ array/ComplexArray.cpp number/ComplexNumber.cpp array/mainComplexArray.cpp -o mainProg
./mainProg
```

## Compile and Run Unitest
```
g++ array/ComplexArray.cpp number/ComplexNumber.cpp array/testComplexArray.cpp -o testProg
./testProg
```
