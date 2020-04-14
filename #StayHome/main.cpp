#include <iostream>
#include <cstring>
//#include "PersonArr.hpp"
#include <ctime>
#include "ChallangeArr.hpp"

char *addChar(char *name, const char s)
{
    char *result;

    result = new char[strlen(name) + 1];
    strcpy(result, name);
    result[strlen(name) - 1] = s;
    //delete[] name;
    result[strlen(name)] = '\0';
    return result;
}

int main()
{
    srand(time(0));
    Person a("Ivancho", "n@", rand() % 100);

    Person b("Kimor", rand() % 100);

    Person c("ee", "ne@", rand() % 100);
    Person d("niki", 27, rand() % 100);

    // Person *arr = new Person[4]{a, b, c, d};
    Person *arr = new Person[4];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    //arr[3].print();
    // Person *brr = new Person[1];
    // brr[0] = b;
    PersonArr p(arr, 4);
    PersonArr Challanged;
    // p += b;
    p.printArr();
    delete[] arr;
    char *text;
    text = new char[50];
    int count = 0, counter;
    std::cout << "Write how many people u will challange: ";
    std::cin >> counter;
    while (std::cin && count < counter)
    {

        std::cin >> text;
        if (Contains(text, p))
        {

            //  Contains(text,p,z);
            for (size_t i = 0; i < p.getSize(); i++)
            {
                if (strcmp(text, p[i].getName()) == 0)
                {
                    Challanged += p[i];
                    std::cout << text << "\n";
                }
            }
        }

        count++;
    }
    Challanged.printArr();
    delete[] text;

    Challange ch("niki", "b", Challanged, p);
    Challange zh("Ivancho", "a", Challanged, p);
    Challange * crr = new Challange[1];
    
   // Challange *crr = new Challange[1]{ch};
    crr[0] = ch;
    //zh.printChallange();
   // std::cout << ch.getSize() << "\n";
    ChallangeArr cha(crr, 1);
     cha.add(ch);
    cha.printCArr();
    // char *name = new char[2];
    // name[0] = 'a';
    // name[1] = 'b';
    // char s = 's';
    // name = addChar(name,s);
    // //addChar(name,'a');

    // char *name2 = new char[4];

    // name2 = addChar(name, s);
    // // strcpy(name2,addChar(name,'s'));
    // for (size_t i = 0; i < strlen(name); i++)
    // {
    //     std::cout << name[i];
    // }

    //a.profile_info("Ivancho");
    //     Person* arr = new Person[1];
    //     arr[0] = a;
    //     PersonArr array(arr,1);
    //     array.printArr();
    //     delete[]arr;
    // std::cout << rand() % 100;
    // std::cout << rand() % 100;
    return 0;
}