#include <iostream>
#include "Person.h"
#include <iostream>
//g++ main.cpp Person.cpp
int main()
{
Person a("nikolay",12);

std::cout<<a.getName()<<" "<<a.getId();
    return 0;
}