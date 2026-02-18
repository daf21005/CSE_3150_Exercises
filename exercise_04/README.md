# CSE 3150 Exercise 4

In this exercise we are expanding on CPython integer where we a implementing:  
1. Constructors
2. Copy Constructor
3. Destructor
4. A basic addition operator for CPython integer
5. Unit tests  

The main goal is adding two integers by their size, long long or using arrays to add the bigger numbers.  
One major note for this program, they are limitations here especially when we are adding a number that can fit into long long and a number that is too big. Another thing is when the result of two long longs is too big for a long long, the code doesn't handle this case. This only covers the basic of the instructions. 

## Compile and Run Main Program:
```
g++ PyLongObject.cpp MainPyLongObject.cpp -o mainProgram
./mainProgram
```

## Compile and Run Unit Test:
```
g++ testPyLongObject.cpp PyLongObject.cpp -o testProgram
./testProgram
```
