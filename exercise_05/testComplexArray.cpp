#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "ComplexArray.h"

TEST_CASE("Default Constructor"){
    ComplexArray complexArray;
    CHECK(complexArray.getSize() == 0);

}