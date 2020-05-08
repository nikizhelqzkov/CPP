#include "Date.h"
#include "Client.h"
#include "Room.h"
#include "Event.h"
#include "DataOfRooms.h"
#include <ctime>
#include <iostream>
//g++ main.cpp Date.cpp Client.cpp Room.cpp Event.cpp DataOfRooms.cpp
//datite da sa subota i  nedelq
void readTORoom(Client &c, std::vector<std::vector<Client>> &v)
{
    c.read();
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            v[i][j].setName("FREE PLACE");
        }
    }

    v[c.getRow() - 1][c.getCol() - 1] = c;
}
int main()
{
    std::cout << "Live Date: ";
    srand(time(0));
    Date z1;
    z1.getLiveData();
    z1.print();
    std::cout << std::endl;
    std::string a;
    bool open = false;
    bool help = false;
    bool save = false;
    bool save_as = false;
    bool close = false;
    bool exit = false;
    std::cout << "WELCOME TO THE TICKET CENTER!" << std::endl;
    do
    {
        open = false;
        help = false;
        save = false;
        save_as = false;
        close = false;
        exit = false;
        std::cout << "Write one of the commands: " << std::endl
                  << "1)open" << std::endl
                  << "2)help" << std::endl
                  << "3)save" << std::endl
                  << "4)save_as" << std::endl
                  << "5)close" << std::endl
                  << "6)exit" << std::endl;

        std::cin >> a;
        if (a == "open" || a == "Open" || a == "OPEN")
        {
            open = true;
            int num; //for returning back
            std::cin >> num;
            if (num == 1)
            {
                open = false;
            }
        }
        else if (a == "help" || a == "Help" || a == "HELP")
        {
            help = true;
        }
        else if (a == "save" || a == "Save" || a == "SAVE")
        {
            save = true;
        }
        else if (a == "save_as" || a == "Save_as" || a == "SAVE_AS" || a == "Save_As")
        {
            save_as = true;
        }
        else if (a == "close" || a == "Close" || a == "CLOSE")
        {
            close = true;
            std::cout << "YOU CLOSED THE FILE!!!!\n";
            std::cout << "NOW WE WILL RETURN BACK TO THE START MENU!!!\n\n\n\n\n";
            close = false;
        }
        else if (a == "help" || a == "Help" || a == "HELP")
        {
            help = true;
        }
        else if (a == "exit" || a == "Exit" || a == "EXIT")
        {
            exit = true;
            std::cout << "GOOD BYE !!!\n";
            return 0;
        }
        else
        {
            std::cout << "WRITE AGAIN CORRECT COMMAND\n\n\n";
        }

    } while (!open && !help && !save && !save_as && !close && !exit);

    Date d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;
    Client c, d, e;
    //c.read();d.read();
    // e.read();

    std::vector<std::vector<Client>> v(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v2(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v3(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v4(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v5(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v6(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v7(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v8(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v9(7, std::vector<Client>(7));
    readTORoom(e, v);

    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         v[i][j].setName("FREE PLACE");
    //     }
    // }

    // v[e.getRow() - 1][e.getCol() - 1] = e;

    // std::cout<<v[2].size();

    Room club(rand() % 100, v, 7, 7);
    Room club2(rand() % 100, v2, 7, 7);
    Room club3(rand() % 100, v3, 7, 7);
    Room club4(rand() % 100, v4, 7, 7);
    Room club5(rand() % 100, v5, 7, 7);
    Room club6(rand() % 100, v6, 7, 7);
    Room club7(rand() % 100, v7, 7, 7);
    Room club8(rand() % 100, v8, 7, 7);
    Room club9(rand() % 100, v9, 7, 7);

    club.print();

    Event kolos(d1, "kolos", club.getId(), v, 7, 7);
    kolos.print();
     RoomArr studio;
    studio.addEvent(kolos);
    studio.freeseats("kolos",d1);
    //  Date date(25,06,2000);
    //  date.print();
    // size_t id = 3;
    //int **a = new int *[3];

    // int row = 3;
    // int col = 2;
    // int counter = 1;
    // for (int i = 0; i < row; ++i)
    // {
    //     a[i] = new int[col];
    // }
    // for (int i = 0; i < row; ++i)
    // {
    //     for (int j = 0; j < col; ++j)
    //     {
    //         std::cin>>a[i][j];
    //     }
    // }

    // Room A(3, a, row, col);

    // A.print();

    // for (size_t i = 0; i < row; i++)
    // {
    //     delete[] a[i];
    // }
    // delete[] a;

    return 0;
}