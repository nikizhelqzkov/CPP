#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ElementsFactory.h"
#include "formula.h"
#include "formula2.h"
#include "book.h"
#include "Person.h"
//g++ main.cpp gold.cpp energy.cpp metal.cpp air.cpp fire.cpp earth.cpp water.cpp spirit.cpp stone.cpp philosopheStone.cpp uravnenie.cpp baseFormula.cpp formula.cpp formula2.cpp book.cpp ElementsFactory.cpp countElements.cpp ElementsCountStorage.cpp Person.cpp

int main()
{
    Book book;

    std::ifstream in("book.txt");
    if (!in.is_open())
    {
        std::cout << "not open\n";
    }
    bool equal = true;
    while (!in.eof())
    {
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
        }

        else
        {
            equal = true;
            std::vector<Elements *> v2;
            v2.push_back(ElementsFactory::readElements(in, str));

            while (equal)
            {

                in >> str;

                if (str == "=")
                {
                    equal = false;
                    std::getline(in, str, '\n');
                    str.erase(0, 1);
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
        }
    }
      std::cout << "\n\n============YOUR VALID FORMULAS=============\n\n";
    book.print();
    in.close();

    std::vector<CountElements> c_data;
/**
 * @brief входа е число интервал името на базов елемент почващ с главна буква. 
 * Алгоритъма работи четейки формулите от горе до мястото на фил. камък.
 * Не работи с примера,защото алгоритъма ми не търси правилните формули,
 * а просто чете формулите както са във файла и както изглеждат след валидация
 * работи с реда на формулите от 3 страница на домашното и той е записан във файла сега
 * https://github.com/nikizhelqzkov/c-/tree/oop/Alhimiq
 */
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
