#include <iostream>
#include <fstream>
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
#include "ElementsFactory.cpp"
#include "countElements.cpp"
#include "ElementsCountStorage.cpp"
#include "Person.cpp"
//#include "ElementsFactory.h"
//#include "formula.h"
//#include "formula2.h"
//#include "book.h"
//g++ main.cpp gold.cpp energy.cpp metal.cpp air.cpp fire.cpp earth.cpp water.cpp spirit.cpp stone.cpp philosopheStone.cpp uravnenie.cpp baseFormula.cpp formula.cpp formula2.cpp book.cpp ElementsFactory.cpp

int main()
{

    //  Energy en;
    //  en.print()
    // Spirit sp;
    // Metal m;
    // Stone stone;
    // //m.print();
    // Fire f;
    // std::cout << "\n";
    // // f.print();
    // std::cout << "\n";
    // Gold gold;
    // Water w;
    // //w.print();
    // std::cout << "\n";
    // Air a;
    // // a.print();
    // //std::cout << "\n"
    // //      << m.getName() << " " << f.getName() << " " << w.getName() << " " << a.getName() << std::endl;

    // PS ps;
    // //ps.print();

    // std::vector<Elements *> data{&m, &f, &w};
    // Uravnenie u(data);
    // //u.print();

    // std::cout << "=========== FORMULA ===========\n\n";
    // Formula formula(u, &w);
    // std::cout << formula.isItValid() << "\n";

    // formula.print();
    // std::cout << "\n\n=========== FORMULA 2 ===========\n\n";
    // std::vector<Elements *> data2{&gold};
    // Uravnenie Ur(data2);
    // Formula2 formula2(Ur);
    // std::cout << formula2.isItValid() << "\n";

    // formula2.print();
    // Earth e;
    // std::cout << "\n\n=========== VALIDATION ===========\n\n";
    // std::vector<Elements *> data3{&w, &e};
    // Uravnenie u3(data3);
    // Formula f3(u3, &m);
    // f3.print();
    // std::cout << f3.isItValid() << "\n";

    // std::cout << "\n\n=========== Book ===========\n\n";
    Book book;
    // book.addFormula(&formula);
    // book.addFormula(&formula2);
    // book.addFormula(&f3);
    // book.print();

    std::ifstream in("book.txt");
    if (!in.is_open())
    {
        std::cout << "not open\n";
    }
    bool equal = true;
    while (!in.eof())
    {
        //std::cout << "\n";
        std::string str;
        in >> str;
        char c = str[0];
        if (c == '/')
        {

            std::vector<Elements *> v;
            str.erase(0, 1);
            v.push_back(ElementsFactory::readElements(in, str));
            Uravnenie ur(v);
            Formula2 f2(ur);
            book.addFormula(&f2);
            // book.print();
            // std::cout << "/" << str << " \n";
        }

        else
        {
            equal = true;
            //std::cout << str << " ";
            std::vector<Elements *> v2;
            v2.push_back(ElementsFactory::readElements(in, str));

            while (equal)
            {

                in >> str;
                //std::cout << str << " ";

                if (str == "=")
                {
                    equal = false;
                    std::getline(in, str, '\n');
                    str.erase(0, 1);
                    //  std::cout << str << " ";
                    Uravnenie ur(v2);

                    Formula f1(ur, ElementsFactory::readElements(in, str));
                    f1.print();
                    book.addFormula(&f1);
                }
                else if (str != "=" && str != "+")
                {
                    v2.push_back(ElementsFactory::readElements(in, str));
                }
            }

            //
            //
            // f1.print();
        }
    }
      std::cout << "\n\n============YOUR VALID FORMULAS=============\n\n";
    book.print();
    in.close();

    std::vector<CountElements> c_data;

    std::cout << "\n\n============YOUR ELEMENTS=============\n\n";
    for (size_t i = 0; i < 4; i++)
    {
        int count;
        std::string nameOfEl;
        std::cout << "Write count of basic element and the name of the element:\n";
        std::cin >> count >> nameOfEl;
        CountElements c(nameOfEl, count);
        c_data.push_back(c);
    }
    ElementsCountStorage storage(c_data);
    Person person(book, storage);
    std::cout << "\n=============IS IT WORKING=============\n\n";
    if (person.isItValid())
    {
        std::cout << "Yes, it is!\n";
    }
    else
    {
        std::cout << "No, it isn't!\n";
    }
    

    return 0;
}
