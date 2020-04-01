#include <iostream>
#include <cmath>
#include "ComplexNumberClass.h"
#include "ComplexNumberFunctions.cpp"

int main()
{
    ComplexNumber a1(9,3);
    double a;
    ComplexNumber a2(8,3);
    ComplexNumber a3;
    a3 = a1+a2;
    a3.print();
    a3 = a1*a2;
    a3.print();
    a3 = a1-a2;
    a3.print();
    std::cout<<a1.absOfComplex()<<std::endl;
    a1-=a2;
    a1.print();
    


}
