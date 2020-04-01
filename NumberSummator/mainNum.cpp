#include <iostream>
#include "numF.cpp"
#include "num.h"


int main()
{
    NumberSummator s(10);
    std::cout << s.getSum() << "\n";
    s.add(9);
    std::cout << s.getSum() << "\n";
    s.sub(1);
    std::cout << s.getSum() << "\n";
    std::cout << s.getCount() << "\n";
    std::cout << s.average() << "\n";
  
    return 0;
}