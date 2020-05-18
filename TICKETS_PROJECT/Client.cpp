#include "Client.h"
#include <iostream>
//#include "Room.h"
//#include "DataOfRooms.cpp"

Client::Client()
{
    this->row = 0;
    this->col = 0;
    this->reserve = false;
    this->buy = false;
    this->note = "";
    this->name = "";
    this->serialNumber = 0;
}
Client::Client(int row, int col, Date date, std::string name, std::string note) : row(row), col(col), reserve(false), buy(false), name(name), note(note)
{
    this->date.setDay(date.getDay());
    this->date.setMonth(date.getMonth());
    this->date.setYear(date.getYear());
}
void Client::print()
{
    std::cout << "CLIENT-> Row: " << this->row << ", Column: " << this->col;
    if (buy)
        std::cout << ", TICKET BOUGHT";
    else if (reserve)
        std::cout << ", TICKED RESERVED";
    std::cout << ",  DATE: ";
    this->date.print();
    std::cout << ", Name: " << name << " , Note: " << this->note;
    if (buy)
    {
        std::cout << " , Ticket Number: " << serialNumber << "; ";
    }
    else
    {
        std::cout << " ;";
    }
}
void Client::print(std::ostream &out)
{
    out << this->row << " " << this->col << " ";
    if (buy)
        out << "10";
    else if (reserve)
        out << "01";
    else
    {
        out << "0";
    }

    out << " ";
    this->date.print(out);
    out << " " << name;
    if (note == "0" || note == "" || note == " ")
    {
        out << " "
            << "0";
    }
    else
    {
        out << " " << this->note;
    }

    if (buy)
    {
        out << " " << serialNumber;
    }
    else
    {
        out << " 0";
    }
}

Date Client::getDate() const
{
    return this->date;
}
void Client::setDate(const Date &date)
{
    this->date = date;
}
void Client::read()

{
    //RoomArr data;

    // std::cout << "Date of Event: \n";
    // do
    // {
    // this->date.read();

    //this->getRooms(data);
    //  flag = this->getRooms(data);

    // } while (!flag);
    bool flag = true;
    do
    {
        flag = true;

        std::cout << "BUY/RESERVE: ";
        std::string type;
        std::getline(std::cin, type);
        if (type == "buy" || type == "BUY" || type == "Buy")
        {
            this->buy = true;
        }
        else if (type == "reserve" || type == "RESERVE" || type == "Reserve")
        {
            this->reserve = true;
        }
        else
        {
            std::cout << "Write again command:\n";
            flag = false;
        }
    } while (!flag);

    std::cout << "Number of row: ";
    std::cin >> this->row;
    std::cout << "Number of column of " << this->row << " row: ";
    std::cin >> this->col;
    // this->date.read();
    std::cin.ignore(1, '\n');
    // std::cout << "\n";
    //std::string c;
    std::cout << "Name: ";
    std::getline(std::cin, this->name);
    std::cout << "Note: ";
    std::getline(std::cin, this->note);
    if (buy)
    {
        serialNumber = 2 * (row + 1) + 4 * (col + 1) + this->date.getDay() * this->date.getMonth() * this->date.getYear();
    }
}
void Client::read(std::istream &in)
{
    std::string bOrR;
    in >> row >> col;
    in >> bOrR;
    int day, month, year;
    in >> year >> month >> day;

    Date d(day, month, year);
    this->setDate(d);
    if (bOrR == "01")
    {
        this->reserve = true;
        this->buy = false;
    }
    else if (bOrR == "10")
    {
        this->buy = true;
        this->reserve = false;
    }
    else if (bOrR == "0")
    {
        this->buy = false;
        this->reserve = false;
    }
    in >> name;
    in >> note;
    in >> serialNumber;
    // return in;
}
int Client::getRow() const
{
    return this->row;
}
int Client::getCol() const
{
    return this->col;
}
std::string Client::getName() const
{
    return name;
}

std::string Client::getNote() const
{
    return note;
}
void Client::setName(std::string name)
{
    this->name = name;
}
bool Client::getReserve() const
{
    return reserve;
}
bool Client::getBuy() const
{
    return buy;
}
long unsigned int Client::getTicket() const
{
    return serialNumber;
}

void Client::checkCode()

{
    std::cout << "Date: " << date << "\n";
    std::cout << "row:" << row << ", place on a row: " << col << std::endl;
}
Client &Client::remove()
{
    this->row = 0;
    this->col = 0;
    this->reserve = false;
    this->buy = false;
    this->note = "";
    this->name = "FREE";
    this->serialNumber = 0;
    this->date.setDay(1);
    this->date.setMonth(1);
    this->date.setYear(1);
    return *this;
}

// bool Client::getRooms(const RoomArr &data)
// {
//     bool flag = false;
//     for (int i = 0; i < data.getSize(); i++)
//     {
//         if (data[i].getDate().isEqual(this->date))
//         {
//             flag = true;
//             std::cout << data[i].getId() << "  ";
//         }
//     }

//     if (!flag)
//     {
//         std::cout << "No events on this Date!\n";
//         return false;
//     }
//     return true;
// }