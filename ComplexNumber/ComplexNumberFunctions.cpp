#include <iostream>
#include <cassert>
#include <cmath>
#include "ComplexNumberClass.h"

ComplexNumber::ComplexNumber()
{
    this->a = 1;
    this->b = 1;
}
ComplexNumber::ComplexNumber(double a, double b)
{
    this->setComplex(a, b);
}
ComplexNumber::ComplexNumber(const ComplexNumber &c)
{
    this->a = c.a;
    this->b = c.b;
}
bool ComplexNumber::operator!()
{
    return this->a == 0 && this->b == 0;
}
double ComplexNumber::getA() const
{
    return this->a;
}
double ComplexNumber::getB() const
{
    return this->b;
}
void ComplexNumber::setA(double other)
{
    this->a = other;
}
void ComplexNumber::setB(double other2)
{
    this->b = other2;
}
void ComplexNumber::setComplex(const double otherA, const double otherB)
{
    if (this->operator!())
    {
        std::cout << "THE COMPLEX NUMBER IS 0";
    }
    assert(this->operator!() == 0);
    this->a = otherA;
    this->b = otherB;
}
double ComplexNumber::absOfComplex()
{
    return sqrt(a * a + b * b);
}
// ComplexNumber ComplexNumber::operator+(ComplexNumber other)
// {
//     ComplexNumber result;
//     result.a = this->a + other.a;
//     result.b = this->b + other.b;
//     return result;
// }
// void ComplexNumber::operator+=(ComplexNumber other)
// {
//     this->a += other.a;
//     this->b += other.b;
// }
ComplexNumber ComplexNumber::operator-(ComplexNumber other)
{
    ComplexNumber result;
    result.a = this->a - other.a;
    result.b = this->b - other.b;
    return result;
}
void ComplexNumber::operator-=(ComplexNumber other)
{
    this->a -= other.a;
    this->b -= other.b;
}
// ComplexNumber ComplexNumber::operator*(ComplexNumber other)
// {
//     ComplexNumber result;
//     result.a = this->a * other.a - this->b * other.b;
//     result.b = this->a * other.b - this->b * other.a;
//     return result;
// }

ComplexNumber operator+(ComplexNumber a, ComplexNumber c)
{
    ComplexNumber result;
    result.setA(c.getA() + a.getA());
    result.setB(c.getB() + a.getB());
    return result;
}
void operator+=(ComplexNumber &a, ComplexNumber c)
{
    a.setComplex(a.getA() + c.getA(), a.getB() + c.getB());
}
ComplexNumber operator+(double a, ComplexNumber c)
{
    ComplexNumber result;
    result.setA(a + c.getA());
    result.setB(0 + c.getB());
    return result;
}
void operator+=(double a, ComplexNumber c)
{

    c.setA(a + c.getA());
    c.setB(0 + c.getB());
}

ComplexNumber operator*(ComplexNumber a, ComplexNumber c)
{
    ComplexNumber result;
    result.setA(a.getA() * c.getA() - a.getB() * c.getB());
    result.setB(a.getA() * c.getB() - a.getB() * c.getA());
    return result;
}
ComplexNumber operator*(double a, ComplexNumber c)
{
    ComplexNumber result;
    result.setA(a * c.getA());
    result.setB(a * c.getB());
    return result;
}
void ComplexNumber::print()
{
    if (this->b == 0)
    {
        std::cout << this->a << std::endl;
    }
    else
    {
        std::cout << this->a << '+' << this->b << "i\n";
    }
}