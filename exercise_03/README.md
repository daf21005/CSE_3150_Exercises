# CSE 3150 Exercise 3 - C++ Structs linked lists
Similar to exercise 2 we are using linked lists instead of a single array to store the students data. There is a change within the formating of these files where before in exercise 2, my header file contained both declarations and definitions of my constructors and destructors. Now with this exercise, I fixed the formating where the header file is now just declaring while the cpp file is giving the defintion of our function, constructor, destructor, and copy constructor. 


Here is a little visual of this exercise:  
Node(Student_1) -> Node(Student_2) -> Node(Student_3) -> Node(Student_n)
Student_1:
Name: "John"
Final: "98"
Homeworks[numHomeworks]

## Compilation and Execution
Here is how to compile the program, using three files linking them together:
```
g++ Student.cpp StudentMain.cpp LinkedList.cpp
./a.out
```

Here is how to compile and run the unit test (we are using doctest for unit testing):
```
g++ Student.cpp LinkedList.cpp testStudent.cpp -o test_student
./test_student
```
