#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "./include/doctest.h" 
#include "PyLongObject.h"


TEST_CASE("default constructor") {
  PyLongObject a;
  CHECK(a.getSmallValue() == 0);
}

TEST_CASE("parameterized constructor") {
  PyLongObject a(42);
  CHECK(a.getSmallValue() == 42);

  PyLongObject b(-25);
  CHECK(b.getSmallValue() == -25);

}

TEST_CASE("copy constructor") {
  PyLongObject a(42);
  PyLongObject b(a);
  CHECK(b.getSmallValue() == 42);
  // or we can use the == operator that was created to make sure the copy works
  // CHECK((a==b)==true);
}

TEST_CASE("equality operator") {
  PyLongObject a(25);
  PyLongObject b(a);
  PyLongObject c(25);
  PyLongObject d(48);

  CHECK((a==b)==true);
  CHECK((a==c)==true);
  CHECK((a==d)==false);
}

TEST_CASE("addition of two small values") {
  PyLongObject a(45);
  PyLongObject b(25);
  PyLongObject c = a + b;

  CHECK(c.getSmallValue() == 70);
}

TEST_CASE("addition with negative numbers") {
  PyLongObject a(50);
  PyLongObject b(-20);
  PyLongObject c = a + b;

  CHECK(c.getSmallValue() == 30);
}

TEST_CASE("addition with zero") {
  PyLongObject a(42);
  PyLongObject b(0);
  PyLongObject c = a + b;

  CHECK(c.getSmallValue() == 42);
}

TEST_CASE("addition of two large values - no carry") {
  // a = 5 + 3 * 2^30
  PyLongObject a;
  a.sign = 1;
  a.fitsInLongLong = false;
  a.numDigits = 2;
  a.digitsBase30 = new unsigned[2];
  a.digitsBase30[0] = 5;
  a.digitsBase30[1] = 3;

  // b = 4 + 2 * 2^30
  PyLongObject b;
  b.sign = 1;
  b.fitsInLongLong = false;
  b.numDigits = 2;
  b.digitsBase30 = new unsigned[2];
  b.digitsBase30[0] = 4;
  b.digitsBase30[1] = 2;

  // result should be 9 + 5 * 2^30
  PyLongObject c = a + b;
  CHECK(c.getDigitN(0) == 9);
  CHECK(c.getDigitN(1) == 5);
}