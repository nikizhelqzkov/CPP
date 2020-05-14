#include <iostream>
#include <string>
#include <vector>
//#include "metal.h"
//#include "air.h"
//#include "fire.h"
//#include "earth.h"
//#include "water.h"
#include "gold.h"
// #include "spirit.h"
//#include "stone.h"
#include "energy.h"
//g++ main.cpp gold.cpp energy.cpp metal.cpp air.cpp fire.cpp earth.cpp water.cpp spirit.cpp stone.cpp

int main()
{

    Metal m;
    m.print();
    Fire f;
    std::cout << "\n";
    f.print();
    std::cout << "\n";

    Water w;
    w.print();
    std::cout << "\n";
    Air a;
    a.print();
    std::cout << "\n"
              << m.getName() << " " << f.getName() << " " << w.getName() << " " << a.getName() << std::endl;
    return 0;
}
