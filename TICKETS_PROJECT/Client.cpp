#include "Client.h"
#include <iostream>
#include "Room.h"
//#include "DataOfRooms.cpp"

Client::Client()
{
    this->row = 0;
    this->col = 0;

    this->note = "";
}
Client::Client(int row, int col, Date date, std::string note)
{
    this->row = row;
    this->col = col;
    this->date.setDay(date.getDay());
    this->date.setMonth(date.getMonth());
    this->date.setYear(date.getYear());

    this->note = note;
}
void Client::print()
{
    std::cout << "CLIENT-> Row: " << this->row << ", Column: " << this->col << ",  DATE: ";
    this->date.print();
    std::cout << " , Note: " << this->note << "; ";
}

Date Client::getDate() const
{
    return this->date;
}
void Client::read()
{
    //RoomArr data;
    // bool flag = true;
    // std::cout << "Date of Event: \n";
    // do
    // {
    // this->date.read();

    //this->getRooms(data);
    //  flag = this->getRooms(data);

    // } while (!flag);

    std::cout << "Number of row: ";
    std::cin >> this->row;
    std::cout << "Number of column of " << this->row << " row: ";
    std::cin >> this->col;
    this->date.read();
    std::cin.ignore(1, '\n');
    // std::cout << "\n";
    //std::string c;

    std::cout << "Note: ";
    std::getline(std::cin, this->note);
}
int Client::getRow() const
{
    return this->row;
}
int Client::getCol() const
{
    return this->col;
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