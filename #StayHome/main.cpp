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
    Person *arr = new Person[1];
    Person testUser("Ivancho", "n@", rand() % 100);
    arr[0] = testUser;
    PersonArr ar(arr, 1);
    PersonArr Challanged;
    Challange ivancho("Ivancho", "kurnik", Challanged, ar);
    Challange *crr = new Challange[1];

    // // Challange *crr = new Challange[1]{ch};
    crr[0] = ivancho;
    // //zh.printChallange();
    // // std::cout << ch.getSize() << "\n";
    ChallangeArr cha(crr, 1);

    srand(time(0));

    int method;

    do
    {
        std::cout << "Welcome to Challange!\n Choose methods:\n 1) register \n 2) Challange\n 3) finish \n 4) exit\n\n";
        std::cin >> method;

        if (method == 1)
        {
            int regMeth;
            do
            {

                std::cout << "\n WELCOME TO REGISTER PART! \n Register: \n 1) without email \n 2)without years \n 3) full register \n 0)back \n";
                std::cin >> regMeth;
                if (regMeth == 1)
                {
                    char *text = new char[50];
                    int a;
                    std::cin >> text >> a;
                    Person user(text, a, rand() % 100);
                    if (ar[0] == testUser)
                    {
                        ar[0] = user;
                    }
                    else
                    {
                        ar += user;
                    }

                    delete[] text;
                }
                else if (regMeth == 2)
                {
                    char *text = new char[50];
                    char *emailText = new char[50];
                    std::cin >> text >> emailText;
                    Person user2(text, emailText, rand() % 100);
                    if (ar[0] == testUser)
                    {
                        ar[0] = user2;
                    }
                    else
                    {
                        ar += user2;
                    }
                    delete[] text;
                    delete[] emailText;
                }
                else if (regMeth == 3)
                {
                    char *text = new char[50];
                    int a;
                    char *emailText = new char[50];
                    std::cin >> text >> a >> emailText;
                    Person user3(text, a, emailText, rand() % 100);
                    if (ar[0] == testUser)
                    {
                        ar[0] = user3;
                    }
                    else
                    {
                        ar += user3;
                    }
                }
                else if (regMeth != 0 && regMeth != 1 && regMeth != 2 && regMeth != 3)
                {
                    std::cout << "WRONG NUMBER --> EXIT APP";
                    return 0;
                }
            } while (regMeth != 0);
        }
        else if (method == 2)
        {
            std::cout << "\n WELCOME TO CHALLANGE MODE!\n ";
            int count = 0, counter;
            char *text = new char[50];
            char *name = new char[30];
            char *tag = new char[30];
            std::cout << "Write how many people u will challange: ";
            std::cin >> counter;
            std::cout << "Write Your name(you have to be registered), challange tag and challanged users:\n";
            std::cin >> name >> tag >> text;
            if (Contains(name, ar))
            {
                PersonArr ChallangedUsers;
                while (std::cin && count < counter)
                {
                    if (count == 0)
                    {
                        if (Contains(text, ar))
                        {

                            //  Contains(text,p,z);
                            for (size_t i = 0; i < ar.getSize(); i++)
                            {
                                if (strcmp(text, ar[i].getName()) == 0)
                                {
                                    ChallangedUsers += ar[i];
                                    std::cout << text << "\n";
                                }
                            }
                        }

                        count++;
                    }
                    else
                    {
                        std::cin >> text;
                        if (Contains(text, ar))
                        {

                            //  Contains(text,p,z);
                            for (size_t i = 0; i < ar.getSize(); i++)
                            {
                                if (strcmp(text, ar[i].getName()) == 0)
                                {
                                    ChallangedUsers += ar[i];
                                    std::cout << text << "\n";
                                }
                            }
                        }

                        count++;
                    }
                }
                Challange userCHallange(name, tag, ChallangedUsers, ar);
                if (cha[0] == ivancho)
                {
                    cha[0] = userCHallange;
                }
                else
                {
                    cha.add(userCHallange);
                }
                delete[]name;
                delete[]tag;
                delete[]text;
               // cha.printCArr();
            }
        }
        else if (method == 3)
        {
            std::cout << "WELCOME TO FINISH CHALLANGE MODE!\n CHOOSE FROM 2 OPTIONS\n 1)Check profile_info (to know your id)\n 2)start finish mode\n ";
            int finishOption;
            std::cin >> finishOption;
            if (finishOption == 1)
            {
            }
            else if (finishOption == 2)
            {
            }
            else
            {
                std::cout << "WRONG NUMBER --> EXIT APP";
                return 0;
            }
        }
        else if (method == 4)
        {
            std::cout << "GOOD BYE! SEE YOU SOON!\n\n";
            ar.printArr();
            return 0;
        }
        else if (method != 1 && method != 2 && method != 3 && method != 4)
        {
            std::cout << "WRONG NUMBER --> EXIT APP";
            return 0;
        }
    } while (method != 4);
    ar.printArr();
    //---------------------------------
    //
    // // Person b("K", rand() % 100);
    // Person b("Kimor", "kim@abv.bg", rand() % 100);
    // Person e("sofi", "n@", rand() % 100);
    // Person c("ee", "ne@", rand() % 100);
    // // Person d("niki", 27,"n@", rand() % 100);
    // Person d("niki", 27, rand() % 100); //-->that constructor i don't know why it kills the challange

    // // Person *arr = new Person[4]{a, b, c, d};
    // Person *arr = new Person[5];
    // arr[0] = a;
    // arr[1] = b;
    // arr[2] = c;
    // arr[3] = d;
    // arr[4] = e;
    // //arr[3].print();
    // // Person *brr = new Person[1];
    // // brr[0] = b;
    // PersonArr p(arr, 5);
    // PersonArr Challanged;
    // // p += b;
    // // p.printArr();
    // delete[] arr;
    // char *text;
    // text = new char[50];
    // int count = 0, counter;
    // std::cout << "Write how many people u will challange: ";
    // std::cin >> counter;
    // while (std::cin && count < counter)
    // {

    //     std::cin >> text;
    //     if (Contains(text, p))
    //     {

    //         //  Contains(text,p,z);
    //         for (size_t i = 0; i < p.getSize(); i++)
    //         {
    //             if (strcmp(text, p[i].getName()) == 0)
    //             {
    //                 Challanged += p[i];
    //                 std::cout << text << "\n";
    //             }
    //         }
    //     }

    //     count++;
    // }
    // Challanged.printArr();
    // delete[] text;

    // Challange ch("ee", "b", Challanged, p);
    // Challange vh("ee", "b", Challanged, p);
    // Challange zh("Ivancho", "a", Challanged, p);
    // Challange mh("ee", "c", Challanged, p);
    // Challange *crr = new Challange[1];

    // // Challange *crr = new Challange[1]{ch};
    // crr[0] = ch;
    // //zh.printChallange();
    // // std::cout << ch.getSize() << "\n";
    // ChallangeArr cha(crr, 1);

    // cha.add(zh);
    // cha.add(vh);
    // cha.add(zh);
    // cha.add(mh);
    // std::cout << "\n----\n";
    // cha.printCArr();
    // std::cout << "\n----\n";

    // //p.printArr();
    // int id,id2;
    // std::cin >> id>>id2;
    // Finish f(cha, "a", id, 7.5);
    // cha = f.RemoveChUsers("a", id, 7.5);
    // cha.printCArr();
    // std::cout << "\n----------------------\n";
    // cha = f.RemoveChUsers("b", id, 8.6);
    // cha.printCArr();
    //  std::cout << "\n----------------------\n";
    // cha = f.RemoveChUsers("b", id2, 5.6);
    // cha.printCArr();
    //      std::cout << "\n----------------------\n";
    // cha = f.RemoveChUsers("b", id, 5.6);
    // cha.printCArr();

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