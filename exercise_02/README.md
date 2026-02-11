# CSE 3150 Exercise 2
In this program we learn more on C++ Structs and Vectors where in this exercise we create Students with structs and vectors.

The requirements for a student is a student has a name, integer number (represented as their Final), and dynamicallt allocated array of homework assignment scores. Here is a little visual of a student:

students[0]:  
Name: John  
Final: 85  
hw_grades: [...]

For this assignment we want to add more than 1 student so we'll have am array of students that holds their name, final and homework grades. The user may hit control-D to stop the program to print out all of the students.  

## Edge Cases
There is something to note about and it's the program's edge cases. 
- When the user enters less than 1 or too many assignments


## Compiling and Executing
Here is how to compile the program, using two files linking them together:
```
g++ Student.cpp StudentMain.cpp
./a.out
```

Here is how to compile and run the unit test:
```
g++ testStudent.cpp -o test_student
./test_student
```

