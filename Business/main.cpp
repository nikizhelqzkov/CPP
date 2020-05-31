#include <iostream>
#include "Person.h"
#include "Payer.h"
#include <iostream>
//g++ main.cpp Person.cpp Payer.cpp
int main()
{
    Person a("nikolay", true);
    Payer p("kozeel", 23);

    std::cout << a.getName() << " " << a.getHasPayer() << std::endl;
    if (a.getHasPayer())
    {
        a.setId(p.getId());
    }
    std::cout << a.getId() << "\n";
    std::cout << p.getName() << " " << p.getId() << std::endl;
    return 0;
}