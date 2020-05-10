#include "Date.h"
#include "Client.h"
#include "Room.h"
#include "Event.h"
#include "DataOfRooms.h"
#include <ctime>
#include <iostream>
//#include <algorithm>
//g++ main.cpp Date.cpp Client.cpp Room.cpp Event.cpp DataOfRooms.cpp
//datite da sa subota i  nedelq
bool dateComp(Date i, Date j) { return (i < j); }
Event &readTORoom(Client &c,
                  /*std::vector<std::vector<std::vector<Client>>> &v2*/
                  Event &event)
{
    // std::cout << "Enter the event name: ";
    // std::string name;
    // std::getline(std::cin, name);
    // std::cout << "\n Enter the day, month and year of a event: ";
    // unsigned int d, m, y;
    // std::cin >> d >> m >> y;
    // Date date(d, m, y);
    // for (size_t i = 0; i < studio.getSize(); i++)
    // {
    //     if (studio[i].getName() == name && studio[i].getDate() == date)
    //     {
    std::vector<std::vector<Client>> temp;
    c.read();
    //c.print();
    temp = event.getplaces();

    temp[c.getRow() - 1][c.getCol() - 1] = c;
    event.setMatrix(temp);
    // event.setCols(c.getCol());
    return event;
    //         std::vector<std::vector<Client>> p;
    //         p = v;
    //         studio[i].setMatrix()
    //     }
    // }

    //v2[0][0][0].
}
//
bool helpCommander()

{
    bool help = true;
    bool helpFlag = true;
    std::cout << "\n\nWELCOME TO THE HELPING CENTER\n";
    std::cout << "\nThese are the starting commands that you can use:\n\n";
    std::cout << "1)open --> opens file\n2)save --> saves the opened file on his directory\n";
    std::cout << "3)save_as --> saves the opened file on new directory\n4)close -->close opened file\n";
    std::cout << "5)help --> give some information about your valid commands\n\n";
    do
    {
        std::cout << "Write that number if you are: \n";
        std::cout << "1)Moderator\n2)Client\n";
        int helpN;
        std::cin >> helpN;
        if (helpN == 1)
        {
            std::cout << "\nWelcome Mod!\nThese are your using commands:\n";
            //all mod commands like new event etc
            std::cout << "1)addevent --> adding new event on EventBox \n2)freeseats --> report of freeseats on an event\n";
            std::cout << "3)bookings --> report of reserved tickets on an event\n";
            std::cout << "4)report --> report of bought tickets from one date to other date\n\n";
            //za 4 shte sortirame masiva po data na eventa i shte shte vidim ot koq data da broim biletite
            //std::sort (myvector.begin(), myvector.end(), dateComp);
            std::cout << "PRESS THE b for back!\n";
            char back;
            bool flagHelp = true;
            do
            {
                std::cin >> back;
                if (back == 'b')
                {
                    help = false;
                }
                else
                {
                    flagHelp = false;
                }
            } while (!flagHelp);
        }
        else if (helpN == 2)
        {
            std::cout << "\nWelcome Client!\nThese are your using commands:\n";
            //all mod commands like new event etc
            std::cout << "\n1)book --> reserve a ticket with name and date of the event, your seat, your name and some note\n";
            std::cout << "2)buy --> reserve a ticket with name and date of the event, your seat, your name and some note\n";
            std::cout << "3)unbook --> cancel the reservation\n";
            std::cout << "4)check --> checking your ticket whether is valid and returning information of the ticket\n\n";

            std::cout << "PRESS THE b for back!\n";
            char back;
            bool flagHelp = true;
            do
            {
                std::cin >> back;
                if (back == 'b')
                {
                    help = false;
                }
                else
                {
                    flagHelp = false;
                }
            } while (!flagHelp);
        }
        else
        {
            helpFlag = false;
            std::cout << "Wrong number!\n\n";
        }
    } while (!helpFlag);
    return help;
}
bool closeCommander()
{
    bool close = true;
    std::cout << "\n\nYOU CLOSED THE FILE!!!!\n";
    std::cout << "NOW WE WILL RETURN BACK TO THE START MENU!!!\n\n\n";
    close = false;
    return close;
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
        if (a == "open" || a == "Open" || a == "OPEN" || a == "1")
        {
            open = true;
            int num; //for returning back
            std::cin >> num;
            if (num == 1)
            {
                open = false;
            }
        }
        else if (a == "help" || a == "Help" || a == "HELP" || a == "2")
        {
            help = helpCommander();
        }
        else if (a == "save" || a == "Save" || a == "SAVE" || a == "3")
        {
            save = true;
        }
        else if (a == "save_as" || a == "Save_as" || a == "SAVE_AS" || a == "Save_As" || a == "4")
        {
            save_as = true;
        }
        else if (a == "close" || a == "Close" || a == "CLOSE" || a == "5")
        {
            close = closeCommander();
        }
        else if (a == "exit" || a == "Exit" || a == "EXIT" || a == "6")
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

    Date d1(20, 6, 2020), d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;
    Client c, d, e;

    //c.read();d.read();
    // e.read();
    std::vector<std::vector<std::vector<Client>>> p2(7, std::vector<std::vector<Client>>(7));
    std::vector<std::vector<Client>> v(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v2(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v3(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v4(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v5(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v6(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v7(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v8(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v9(7, std::vector<Client>(7));
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            v[i][j].setName("FREE PLACE");
        }
    }
    Event kolos(d1, "kolos", rand() % 100, v, 7, 7);

    //kolos.print();
    RoomArr studio;
    studio.addEvent(kolos);

    std::cin.ignore(1, '\n');
    std::cout << "\n";
    std::cout << "Enter the event name: ";
    std::string name;

    std::getline(std::cin, name);
    std::cout << name;

    std::cout << "\n Enter the day, month and year of a event: ";
    unsigned int day, m, y;
    std::cin >> day >> m >> y;
    Date date(day, m, y);
    bool isItHave = false;

    for (size_t i = 0; i < studio.getSize(); i++)
    {
        //std::cout << studio[i].getName() << "\n";
        if (studio[i].getName() == name && studio[i].getDate() == date)
        {
            isItHave = true;
            c.setDate(date);
            e.setDate(date);
            // studio[i].print();
            // std::cout << "============================\n";
            studio[i] = readTORoom(e, studio[i]);
            studio[i] = readTORoom(c, studio[i]);
        }
    }
    std::string nameCLose;
    std::cout << "Name of event: ";
    std::getline(std::cin, nameCLose);
    std::cout << "\n Enter the day, month and year of a event: ";
    unsigned int Day, month, year;
    std::cin >> Day >> month >> year;
    Date dateClose(Day, month, year);
    std::cout << "Enter your row and seat of a row: ";
    int row, col;
    std::cin >> row >> col;
    studio = studio.unbook(nameCLose, dateClose, row, col);
    std::cout << "\n";
    studio[0].print();

if (!isItHave)
{
    std::cout << "The event on that date is missing!\n";
}
system("pause");
// for (int i = 0; i < v.size(); i++)
// {
//     for (int j = 0; j < v[i].size(); j++)
//     {
//         v[i][j].setName("FREE PLACE");
//     }
// }

// v[e.getRow() - 1][e.getCol() - 1] = e;

// std::cout<<v[2].size();

// Room club(rand() % 100, v, 7, 7);
// Room club2(rand() % 100, v2, 7, 7);
// Room club3(rand() % 100, v3, 7, 7);
// Room club4(rand() % 100, v4, 7, 7);
// Room club5(rand() % 100, v5, 7, 7);
// Room club6(rand() % 100, v6, 7, 7);
// Room club7(rand() % 100, v7, 7, 7);
// Room club8(rand() % 100, v8, 7, 7);
// Room club9(rand() % 100, v9, 7, 7);

//club.print();

//studio.freeseats("kolos", d1);

//studio.bookings("kolos",d1);
// long unsigned int tN;
// std::cout<<"Your ticket number: ";
// std::cin>>tN;
// studio.checkTicket(tN);

// readTORoom(c, v);
// Room club(club.getId(), v, 7, 7);

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