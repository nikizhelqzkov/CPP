#include <iostream>
#include <cstring>
//#include "PersonArr.hpp"
#include <ctime>
#include "Finish.hpp"

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

    // Person b("K", rand() % 100);
    Person b("Kimor", "kim@abv.bg", rand() % 100);
    Person e("sofi", "n@", rand() % 100);
    Person c("ee", "ne@", rand() % 100);
    // Person d("niki", 27,"n@", rand() % 100);
    Person d("niki", 27, rand() % 100); //-->that constructor i don't know why it kills the challange

    // Person *arr = new Person[4]{a, b, c, d};
    Person *arr = new Person[5];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    arr[4] = e;
    //arr[3].print();
    // Person *brr = new Person[1];
    // brr[0] = b;
    PersonArr p(arr, 5);
    PersonArr Challanged;
    // p += b;
    // p.printArr();
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

    Challange ch("ee", "b", Challanged, p);
    Challange vh("ee", "b", Challanged, p);
    Challange zh("Ivancho", "a", Challanged, p);
    Challange mh("ee", "c", Challanged, p);
    Challange *crr = new Challange[1];

    // Challange *crr = new Challange[1]{ch};
    crr[0] = ch;
    //zh.printChallange();
    // std::cout << ch.getSize() << "\n";
    ChallangeArr cha(crr, 1);

    cha.add(zh);
    cha.add(vh);
    cha.add(zh);
    cha.add(mh);
    std::cout << "\n----\n";
    cha.printCArr();
    std::cout << "\n----\n";

    //p.printArr();
    int id,id2;
    std::cin >> id>>id2;
    Finish f(cha, "a", id, 7.5);
    cha = f.RemoveChUsers("a", id, 7.5);
    cha.printCArr();
    std::cout << "\n----------------------\n";
    cha = f.RemoveChUsers("b", id, 8.6);
    cha.printCArr();
     std::cout << "\n----------------------\n";
    cha = f.RemoveChUsers("b", id2, 5.6);
    cha.printCArr();
         std::cout << "\n----------------------\n";
    cha = f.RemoveChUsers("b", id, 5.6);
    cha.printCArr();
    std::cout<<"0";
    // Finish frs(cha,"b",id,7.5);
    // cha.printCArr();
    //cha.printCArr();
    // cha.listByNewest();
    //   std::cout<<"\n----\n";
    //   //cha.listByOldest();
    //    std::cout<<"\n----\n";
    // cha.listByPopular();
    //cha.printCArr();
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