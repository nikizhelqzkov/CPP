#include <iostream>
#ifndef COMPLEX_NUMBER_H_INCLUDED
#define COMPLEX_NUMBER_H_INCLUDED

class ComplexNumber
{
private:
    double a;
    double b;

public:
    ComplexNumber();
    ComplexNumber(double, double);
    ComplexNumber(const ComplexNumber &);
    double getA() const;
    double getB() const;
    void setA(const double);
    void setB(const double other);
    void setComplex(const double otherA, const double otherB);
    double absOfComplex();
    bool operator!();
    bool isItZero();
    // ComplexNumber operator+(ComplexNumber);
    //void operator+=(ComplexNumber);
    ComplexNumber operator-(ComplexNumber);
    void operator-=(ComplexNumber);
    //ComplexNumber operator*(ComplexNumber);
    void print();
};

#endif