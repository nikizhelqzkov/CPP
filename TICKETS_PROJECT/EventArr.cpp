#include "EventArr.h"
#include <iostream>
EventArr::EventArr()
{
    this->data.clear();
    this->size = 0;
}
EventArr::EventArr(const std::vector<Event> &data, size_t size)
{
    this->data = data;
    this->size = data.size();
}
EventArr::EventArr(const EventArr &other)
{
    this->data = other.data;
    this->size = other.size;
}
EventArr::~EventArr()
{
}
void EventArr::printArr(std::ostream &out) const
{
    out << this->size << "\n";
    for (int i = 0; i < this->size; i++)
    {
        this->data[i].Print(out);
        // std::cout << this->data[i];
    }
}
void EventArr::printArr() const
{
    for (int i = 0; i < this->size; i++)
    {
        // std::cout << this->data[i];
        this->data[i].Print(std::cout);
    }
}
Event &EventArr::operator[](int i)
{
    return this->data[i];
}
Event EventArr::operator[](int i) const
{
    return this->data[i];
}
EventArr &EventArr::addEvent(const Event &other)
{
    bool flag = true;
    if (!this->data.empty())
    {

        for (int i = 0; i < this->size; i++)
        {
            if (data[i].getName() == other.getName() && data[i].getDate() == other.getDate())
            {
                std::cout << "ON THIS DATE THAT EVENT IS SAVED\n";
                return *this;
            }
        }
        //this->data.resize(1);
    }
    this->data.push_back(other);
    this->size++;
    return *this;
}

bool EventArr::removeEvent(const Event &other)
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->data[i].getId() == other.getId())
        {
            this->size--;
            this->data.erase(this->data.begin() + i);
            return true;
        }
    }
    return false;
}
int EventArr::getSize() const
{
    return this->size;
}
std::vector<Event> EventArr::getData() const
{
    return this->data;
}
void EventArr::freeseats(std::string name, Date date)
{
    std::cout << "\n\nFree seats in " << name << " on " << date << ": \n\n";
    for (int i = 0; i < this->data.size(); i++)
    {
        if (data[i].getName() == name && data[i].getDate() == date)
        {
            data[i].printFreeSeats();
        }
    }
}
void EventArr::bookings(std::string name, Date date)
{
    bool res1 = false;
    bool res2 = false;
    bool res3 = false;
    if (name == "")
    {
        std::cout << "\n\nReserve seats on " << date << ": \n\n";
        for (int i = 0; i < this->data.size(); i++)
        {
            if (data[i].getDate() == date)
            {

                std::cout << "Event " << data[i].getName() << ":\n";
                res1 = data[i].reserveFreeSeats();
            }
        }
    }
    else if (date.getYear() == 1)
    {
        std::cout << "\n\nReserve seats in " << name << ": \n\n";
        for (int i = 0; i < this->data.size(); i++)
        {
            if (data[i].getName() == name)
            {

                std::cout << "Event on :" << data[i].getDate() << ":\n";
                res2 = data[i].reserveFreeSeats();
            }
        }
    }
    else
    {
        std::cout << "\n\nReserve seats in " << name << " on " << date << ": \n\n";
        for (int i = 0; i < this->data.size(); i++)
        {
            if (data[i].getName() == name && data[i].getDate() == date)
            {

                res3 = data[i].reserveFreeSeats();
            }
        }
    }
    if (!res1 && !res2 && !res3)
    {
        std::cout << "No reserved tickets !!!\n";
    }
}

void EventArr::boughtTickets(std::string name, Date date)
{
    bool res1 = false;
    bool res2 = false;
    bool res3 = false;
    if (name == "")
    {
        std::cout << "\n\nBought seats on " << date << ": \n\n";
        for (int i = 0; i < this->data.size(); i++)
        {
            if (data[i].getDate() == date)
            {

                std::cout << "Event " << data[i].getName() << ":\n";
                res1 = data[i].bought();
            }
        }
    }
    else if (date.getYear() == 1)
    {
        std::cout << "\n\nBought seats in " << name << ": \n\n";
        for (int i = 0; i < this->data.size(); i++)
        {
            if (data[i].getName() == name)
            {

                std::cout << "Event on :" << data[i].getDate() << ":\n";
                res2 = data[i].bought();
            }
        }
    }
    else
    {
        std::cout << "\n\nBought seats in " << name << " on " << date << ": \n\n";
        for (int i = 0; i < this->data.size(); i++)
        {
            if (data[i].getName() == name && data[i].getDate() == date)
            {

                res3 = data[i].bought();
            }
        }
    }
    if (!res1 && !res2 && !res3)
    {
        std::cout << "No bought tickets !!!\n";
    }
}

void EventArr::checkTicket(long unsigned int serialNumber)
{
    bool flag = false;
    bool valid = false;
    for (int i = 0; i < this->data.size(); i++)
    {
        flag = false;
        flag = data[i].checkCode(serialNumber);
        if (flag)
        {
            valid = true;
        }
    }
    if (!valid)
    {
        std::cout << "THAT TICKET NUMBER IS NOT VALID!!!\n";
    }
}
EventArr &EventArr::unbook(std::string name, Date date, int row, int col)
{
    bool flag = false;
    for (size_t i = 0; i < this->data.size(); i++)
    {
        std::cout << "here 1\n";
        if (this->data[i].getName() == name && this->data[i].getDate() == date)
        {
            flag = true;
            data[i] = data[i].unbook(row, col);
        }
    }
    if (!flag)
    {
        std::cout << "Your reservation is not on this date or in this event\n";
    }
    return *this;
}
void EventArr::report(Date from, Date to)
{
    bool hasBought;
    std::cout << "\n";
    for (auto e : this->data)
    {
        if (from < e.getDate() && e.getDate() < to)
        {

            std::cout << "Event -> " << e.getName() << " , Date: " << e.getDate() << "\n";

            hasBought = e.bought();
            if (!hasBought)
            {
                std::cout << "NO BOUGHT TICKETS!!! \n";
            }
            else
            {
                std::cout << "\n";
            }
            std::cout << "\n";
        }
    }
}