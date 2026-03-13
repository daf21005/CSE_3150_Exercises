#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "ComplexArray.h"

TEST_CASE("Default Constructor"){
    ComplexArray complexArr;
    CHECK(complexArr.getSize() == 0);
}

TEST_CASE("Initialize Constructor"){
    ComplexArray complexArr(5);
    CHECK(complexArr.getSize() == 5);
}

TEST_CASE("Move Constructor"){
    ComplexArray complexArr(5);
    ComplexArray moveArr(std::move(complexArr));
    CHECK(moveArr.getSize() == 5);
}

TEST_CASE("Move Operator"){
    ComplexArray complexArr(5);
    ComplexArray moveArr;

    moveArr = std::move(complexArr);
    CHECK(moveArr.getSize() == 5);
}

TEST_CASE("Put and Get Complex Number"){
    ComplexArray complexArr(5);
    ComplexNumber cn1(1.0, 2.0);
    complexArr.put_complex_number(cn1, 0);

    ComplexNumber & cn2 = complexArr.get_complex_number(0);
    CHECK(cn2.getReal() == 1.0);
    CHECK(cn2.getImag() == 2.0);
}

TEST_CASE("Move Constructor empties source"){
    ComplexArray complexArr(5);
    ComplexArray moveArr(std::move(complexArr));
    CHECK(complexArr.getSize() == 0);  // verify source was emptied
}