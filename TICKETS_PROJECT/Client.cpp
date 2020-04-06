#include "Client.h"
#include <iostream>

Client::Client()
{
    this->row = 0;
    this->col = 0;
    this->name = "";
}
Client::Client(int row, int col, Date date, std::string name)
{
    this->row = row;
    this->col = col;
    this->date.setDay(date.getDay());
    this->date.setMonth(date.getMonth());
    this->date.setYear(date.getYear());
    this->name = name;
}
void Client::print()
{
    std::cout << "CLIENT-> Row: " << this->row << ", Column: " << this->col << ",  DATE: ";
    this->date.print();
    std::cout << " , Name: " << this->name << "; ";
}
void Client::setName(const std::string &other)
{
    this->name = other;
}

std::string Client::getName() const
{
    return this->name;
}
void Client::read()
{

    
    std::cout << "Number of row: ";
    std::cin >> this->row;
    std::cout << "Number of column of " << this->row << " row: ";
    std::cin >> this->col;
    this->date.read();
    std::cin.ignore(1, '\n');
   // std::cout << "\n";
    std::string c;
    std::cout << "Your name: ";
    std::getline(std::cin, c);
    this->name = c;
}