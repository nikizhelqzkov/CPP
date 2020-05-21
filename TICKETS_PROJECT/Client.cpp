#include "Client.h"
#include <iostream>
//#include "Room.h"
//#include "DataOfRooms.cpp"
/**
 * @brief Construct a new Client:: Client object
 * 
 */
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
/**
 * @brief Construct a new Client:: Client object
 * 
 * @param row 
 * @param col 
 * @param date 
 * @param name 
 * @param note 
 */
Client::Client(int row, int col, Date date, std::string name, std::string note) : row(row), col(col), reserve(false), buy(false), name(name), note(note)
{
    this->date.setDay(date.getDay());
    this->date.setMonth(date.getMonth());
    this->date.setYear(date.getYear());
}/**
 * @brief print in a console the data of the client object
 * 
 */
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
        std::cout << " , Ticket Number: " << serialNumber << " \n";
    }
    else
    {
        std::cout << " \n";
    }
}
/**
 * @brief print in file 
 * 
 * @param out 
 */
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
/**
 * @brief get date
 * 
 * @return Date 
 */
Date Client::getDate() const
{
    return this->date;
}
/**
 * @brief set date
 * 
 * @param date 
 */
void Client::setDate(const Date &date)
{
    this->date = date;
}
/**
 * @brief read from console
 * 
 */
void Client::read()

{
    //EventArr data;

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
/**
 * @brief read from file
 * 
 * @param in 
 */
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
}
/**
 * @brief get row
 * 
 * @return int 
 */
int Client::getRow() const
{
    return this->row;
}
/**
 * @brief get column
 * 
 * @return int 
 */
int Client::getCol() const
{
    return this->col;
}
/**
 * @brief get name of the Client
 * 
 * @return std::string 
 */
std::string Client::getName() const
{
    return name;
}
/**
 * @brief get some notes
 * 
 * @return std::string 
 */
std::string Client::getNote() const
{
    return note;
}
/**
 * @brief set name of the client
 * 
 * @param name 
 */
void Client::setName(std::string name)
{
    this->name = name;
}
/**
 * @brief get the bool value if the ticket is reserved
 * 
 * @return true 
 * @return false 
 */
bool Client::getReserve() const
{
    return reserve;
}
/**
 * @brief get the bool value if the ticket is bought
 * 
 * @return true 
 * @return false 
 */
bool Client::getBuy() const
{
    return buy;
}
/**
 * @brief return the ticket number
 * 
 * @return long unsigned int 
 */
long unsigned int Client::getTicket() const
{
    return serialNumber;
}
/**
 * @brief printing the data of the ticket info
 * 
 */
void Client::checkCode()

{
    std::cout << "Date: " << date << "\n";
    std::cout << "row:" << row << ", place on a row: " << col << std::endl;
}
/**
 * @brief remove client object
 * 
 * @return Client& 
 */
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