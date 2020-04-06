#include "Client.h"
#include<iostream>



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