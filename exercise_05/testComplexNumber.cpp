#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "ComplexNumber.h"

TEST_CASE("Default constructor"){
    const double _real{0.0}, _img{0.0};

    ComplexNumber complex;

    CHECK(complex.getReal() == _real);   
    CHECK(complex.getImag() == _img); 
}

TEST_CASE("Custom constructor"){
    const double _real{4.3}, _img{4.0};

    ComplexNumber complex(_real, _img);

    CHECK(complex.getReal() == _real);
    CHECK(complex.getImag() == _img);
}

TEST_CASE("Complex assignment constructor"){
    const double _real{4.3}, _img{4.0};
    const double _realZero{0.0};

    ComplexNumber complex(_real, _img);

    ComplexNumber other;
    CHECK(other.getReal() == _realZero);
    CHECK(other.getImag() == _realZero);

    other = complex;
    CHECK(other.getReal() == complex.getReal());
    CHECK(other.getImag() == complex.getImag()); 
}

TEST_CASE("Complex != test"){
    const double _real{4.3}, _img{4.0};

    ComplexNumber complex(_real, _img);
    ComplexNumber copyComplex = complex;

    ComplexNumber notEqual(_real+2.0, _img - 1.7);

    CHECK(copyComplex.getReal() == complex.getReal());
    CHECK(copyComplex.getImag() == complex.getImag());

    CHECK_FALSE(complex == notEqual);
    CHECK(complex != notEqual);
}

TEST_CASE("Copy Constructor"){
    const double _real{4.3}, _img{4.0};
    ComplexNumber complex(_real, _img), otherComplex;

    otherComplex = complex;

    CHECK(complex.getReal() == otherComplex.getReal());
    CHECK(complex.getImag() == otherComplex.getImag());
}