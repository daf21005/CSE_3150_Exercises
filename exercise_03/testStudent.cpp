#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "./include/doctest.h" 
#include "Student.h"
#include "LinkedList.h"

// testing student
TEST_CASE("Testing initialization of Student struct") {
    Student s;
    CHECK(s.numHomeworks == 0);
    CHECK(s.hw_grades == nullptr);
}

TEST_CASE("Testing parameterized constructor of Student struct") {
    Student s("John", 90, 3);
    CHECK(s.name == "John");
    CHECK(s.final == 90);
    CHECK(s.numHomeworks == 3);
    for (int i = 0; i < s.numHomeworks; i++) {
        s.hw_grades[i] = i * 10; // Assigning some values
    }
    CHECK(s.hw_grades[0] == 0);
    CHECK(s.hw_grades[1] == 10);
    CHECK(s.hw_grades[2] == 20);
}

TEST_CASE("Zero homeworks doesn't crash") {
    Student s("Dave", 88, 0);
    CHECK(s.numHomeworks == 0);
    CHECK(s.hw_grades == nullptr);  // Array allocated but size 0
}

// testing linked lists
TEST_CASE("Insert multiple students into linked list") {
    LinkedList list;

    Student s1("John", 85, 1);
    Student s2("Jane", 90, 1);
    Student s3("Bob", 75, 1);
    s1.hw_grades[0] = 90;
    s2.hw_grades[0] = 95;
    s3.hw_grades[0] = 80;

    list.insert(s1);
    list.insert(s2);
    list.insert(s3);

    CHECK(list.size == 3);
    CHECK(list.isEmpty() == false);
}