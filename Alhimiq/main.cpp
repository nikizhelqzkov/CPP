#include <iostream>
#include <string>
#include <vector>
#include "metal.cpp"
#include "air.cpp"
#include "fire.cpp"
#include "earth.cpp"
#include "water.cpp"
#include "gold.cpp"
#include "spirit.cpp"
#include "stone.cpp"
#include "energy.cpp"
#include "philosopheStone.cpp"
#include "uravnenie.cpp"
#include "baseFormula.cpp"
#include "formula.cpp"
#include "formula2.cpp"
#include "book.cpp"
//#include "formula.h"
//#include "formula2.h"
//#include "book.h"
#include <tuple>
//g++ main.cpp gold.cpp energy.cpp metal.cpp air.cpp fire.cpp earth.cpp water.cpp spirit.cpp stone.cpp philosopheStone.cpp uravnenie.cpp baseFormula.cpp formula.cpp formula2.cpp book.cpp

int main()
{
    Energy en;
    Spirit sp;
    Metal m;
    Stone stone;
    //m.print();
    Fire f;
    std::cout << "\n";
    // f.print();
    std::cout << "\n";
    Gold gold;
    Water w;
    //w.print();
    std::cout << "\n";
    Air a;
    // a.print();
    //std::cout << "\n"
    //      << m.getName() << " " << f.getName() << " " << w.getName() << " " << a.getName() << std::endl;

    PS ps;
    //ps.print();

    std::vector<Elements *> data{&m, &f, &w};
    Uravnenie u(data);
    //u.print();

    std::cout << "=========== FORMULA ===========\n\n";
    Formula formula(u, &w);
    std::cout << formula.isItValid() << "\n";

    formula.print();
    std::cout << "\n\n=========== FORMULA 2 ===========\n\n";
    std::vector<Elements *> data2{&gold};
    Uravnenie Ur(data2);
    Formula2 formula2(Ur);
    std::cout << formula2.isItValid() << "\n";

    formula2.print();
    Earth e;
    std::cout << "\n\n=========== VALIDATION ===========\n\n";
    std::vector<Elements *> data3{&w, &e};
    Uravnenie u3(data3);
    Formula f3(u3, &m);
    std::cout << f3.isItValid() << "\n";

    std::cout << "\n\n=========== Book ===========\n\n";
    Book book;
    book.addFormula(&formula);
    book.addFormula(&formula2);
    book.print();

    return 0;
}
