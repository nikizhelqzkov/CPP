#include <iostream>
#include <cstring>
#include <ctime>
#include "Finish.hpp"
#include <fstream>

int main()
{

    Person *arr = new Person[1];
    Person testUser("niki", "n@", rand() % 100);
    arr[0] = testUser;
    PersonArr ar(arr, 1);
    std::ifstream input("USER.txt", std::ios::in);

    do
    {
        if (input.tellg() == -1)
            break;
        Person per;
        per.read(input);

        if (ar[0] == testUser)
        {
            ar[0] = per;
        }
        else
        {
            ar += per;
        }

    } while (!input.eof());

    input.close();

    PersonArr Challanged;
    Challange ivancho(ar[0].getName(), "test", Challanged, ar);
    Challange *crr = new Challange[1];
    crr[0] = ivancho;
    ChallangeArr cha(crr, 1);

    srand(time(0));

    int method;

    do
    {
        std::cout << "Welcome to Challange!\n Choose methods:\n 1) register \n 2) Challange\n 3) finish \n 4) exit\n 5) list_by\n";
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
                        std::ofstream outputFile("USER.txt", std::ios::out | std::ios::app);
                        if (!outputFile.is_open())
                        {
                            std::cout << "Error! The file cannot be opened!" << std::endl;
                            return 0;
                        }
                        user.print(outputFile);

                        outputFile.close();
                    }
                    else
                    {
                        ar += user;
                        std::ofstream outputFile("USER.txt", std::ios::app);
                        if (!outputFile.is_open())
                        {
                            std::cout << "Error! The file cannot be opened!" << std::endl;
                            return 0;
                        }
                        user.print(outputFile);

                        outputFile.close();
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
                        std::ofstream outputFile("USER.txt", std::ios::app);
                        if (!outputFile.is_open())
                        {
                            std::cout << "Error! The file cannot be opened!" << std::endl;
                            return 0;
                        }
                        user2.print(outputFile);
                        outputFile.close();
                    }
                    else
                    {
                        ar += user2;
                        std::ofstream outputFile("USER.txt", std::ios::app);
                        if (!outputFile.is_open())
                        {
                            std::cout << "Error! The file cannot be opened!" << std::endl;
                            return 0;
                        }
                        user2.print(outputFile);
                        outputFile.close();
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
                        std::ofstream outputFile("USER.txt", std::ios::app);
                        if (!outputFile.is_open())
                        {
                            std::cout << "Error! The file cannot be opened!" << std::endl;
                            return 0;
                        }
                        user3.print(outputFile);
                        outputFile.close();
                    }
                    else
                    {
                        ar += user3;
                        std::ofstream outputFile("USER.txt", std::ios::app);
                        if (!outputFile.is_open())
                        {
                            std::cout << "Error! The file cannot be opened!" << std::endl;
                            return 0;
                        }
                        user3.print(outputFile);
                        outputFile.close();
                    }

                    delete[] text;
                    delete[] emailText;
                }
                else if (regMeth != 0 && regMeth != 1 && regMeth != 2 && regMeth != 3)
                {
                    std::cout << "WRONG NUMBER! TRY AGAIN!\n"; //--> EXIT APP";
                                                               // return 0;
                }
            } while (regMeth != 0);
        }
        else if (method == 2)
        {
            int chOption;
            do
            {
                std::cout << "\n WELCOME TO CHALLANGE MODE!\n ";
                std::cout << "\n CHOOSE OPTION: \n 1)registred users \n 2)Start Challange \n 0)Back \n";
                std::cin >> chOption;
                if (chOption == 1)
                {
                    if (ar[0] == testUser)
                    {
                        std::cout << "NO REGISTRED USERS!\n";
                    }
                    else
                    {

                        ar.printArr(std::cout);
                    }
                }
                else if (chOption == 2)
                {
                    int count = 0, counter;
                    char *text = new char[50];
                    char *name = new char[30];
                    char *tag = new char[30];

                    std::cout << "Write Your name(you have to be registered), challange tag:\n"; //and challanged users:\n";
                    std::cin >> name >> tag;

                    if (Contains(name, ar))
                    {
                        PersonArr ChallangedUsers;
                        std::cout << "Write how many people u will challange: ";
                        std::cin >> counter;
                        std::cout << "Write the challanged users: ";

                        while (std::cin && count < counter)
                        {

                            std::cin >> text;
                            if (Contains(text, ar))
                            {

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
                        Challange userCHallange(name, tag, ChallangedUsers, ar);
                        int lenght;
                        std::ofstream chout("Challanges.bin", std::ios::app | std::ios::binary);

                        if (!chout.is_open())
                        {
                            std::cout << "error, while opening a file!\n";
                        }
                        else
                        {
                            chout.seekp(0, std::ios::end);
                            chout.write(reinterpret_cast<char *>(&userCHallange), sizeof(Challange));
                        }
                        chout.close();

                        if (cha[0] == ivancho)
                        {
                            cha[0] = userCHallange;
                        }
                        else
                        {
                            cha.add(userCHallange);
                        }

                        delete[] name;
                        delete[] tag;
                        delete[] text;

                        cha.printCArr(std::cout);
                    }
                    else
                    {
                        std::cout << "YOUR NAME HAS NOT REGISTRED YET!\n";
                    }
                }
                else if (chOption != 0 && chOption != 1 && chOption != 2)
                {
                    std::cout << "WRONG NUMBER! TRY AGAIN!\n"; //--> EXIT APP";
                }

            } while (chOption != 0);
        }
        else if (method == 3)
        {
            int finishOption;
            do
            {
                std::cout << "WELCOME TO FINISH CHALLANGE MODE!\n CHOOSE FROM 3 OPTIONS: \n 1)Check profile_info (to know your id)\n 2)start finish mode\n 0)back\n ";

                std::cin >> finishOption;
                if (finishOption == 1)
                {
                    if (ar[0] == testUser)
                    {
                        std::cout << "IT HASN'T GOT ANY USERS YET! ";
                    }
                    else
                    {
                        ar.printArr(std::cout);
                    }

                    std::cout << "\n\n";
                }
                else if (finishOption == 2)
                {
                    if (ar[0] == testUser)
                    {
                        std::cout << "NO REGISTRED USERS!\n";
                    }
                    else if (cha[0] == ivancho)
                    {
                        std::cout << "NO CHALLANGES!\n";
                    }
                    else
                    {
                        std::cout << "WRITE YOUR ID, CHALLANGED TAG AND YOUR RATING FOR THIS CHALLANGE: \n";
                        int id;
                        double rating;
                        char *finishTag = new char[30];
                        std::cin >> id >> finishTag >> rating;

                        Finish f(cha, finishTag, id, rating);
                        cha = f.RemoveChUsers(finishTag, id, rating);
                        delete[] finishTag;
                    }
                }

                else if (finishOption != 0 && finishOption != 1 && finishOption != 2)
                {
                    std::cout << "WRONG NUMBER! TRY AGAIN!\n"; //--> EXIT APP";
                }
            } while (finishOption != 0);
        }
        else if (method == 4)
        {
            std::cout << " GOOD BYE! SEE YOU SOON!\n\n";
            if (ar[0] == testUser && cha[0] == ivancho)
            {
                std::cout << " IT HASN'T GOT ANY USERS AND CHALLANGES YET! \n\n";
            }
            else if (cha[0] == ivancho)
            {
                std::cout << "\n USERS: ";
                ar.printArr(std::cout);
                std::cout << " IT HASN'T GOT ANY CHALLANGES YET! \n\n";
            }
            else
            {
                std::cout << "CHALLANGES: ";
                cha.printCArr(std::cout);
                std::cout << "\n USERS: ";
                ar.printArr(std::cout);
            }

            return 0;
        }
        else if (method == 5)
        {
            int listN;
            do
            {
                std::cout << "WELCOME TO LIST OF CHALLANGES!\n CHOOSE YOUR LIST:\n 1)list_by newest\n 2)list_by oldest\n 3)list_by most_popular\n 0)back \n";
                std::cin >> listN;
                if (listN == 1)
                {
                    cha.listByNewest();
                }
                else if (listN == 2)
                {
                    cha.listByOldest();
                }
                else if (listN == 3)
                {
                    cha.listByPopular();
                }
                else if (listN != 1 && listN != 2 && listN != 3 && listN != 0)
                {
                    std::cout << "WRONG NUMBER! TRY AGAIN!\n";
                }

            } while (listN != 0);
        }
        else if (method != 1 && method != 2 && method != 3 && method != 4 && method != 5)
        {
            std::cout << "WRONG NUMBER! TRY AGAIN! \n"; //--> EXIT APP";
        }
    } while (method != 4);

    return 0;
}