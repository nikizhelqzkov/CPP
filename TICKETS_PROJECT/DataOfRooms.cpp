#include "DataOfRooms.h"
#include <iostream>
RoomArr::RoomArr()
{
    this->data.clear();
    this->size = 0;
}
RoomArr::RoomArr(const std::vector<Event> &data, size_t size)
{
    this->data = data;
    this->size = data.size();
}
RoomArr::RoomArr(const RoomArr &other)
{
    this->data = other.data;
    this->size = other.size;
}
RoomArr::~RoomArr()
{
}
void RoomArr::printArr() const
{
    for (int i = 0; i < this->size; i++)
    {
        // std::cout << this->data[i];
        this->data[i].print();
    }
}
Event &RoomArr::operator[](int i)
{
    return this->data[i];
}
Event RoomArr::operator[](int i) const
{
    return this->data[i];
}
RoomArr &RoomArr::addEvent(const Event &other)
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
        this->data.resize(1);
    }
    this->data.push_back(other);
    this->size++;
    return *this;
}

bool RoomArr::removeEvent(const Event &other)
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
int RoomArr::getSize() const
{
    return this->size;
}
std::vector<Event> RoomArr::getData() const
{
    return this->data;
}
void RoomArr::freeseats(std::string name, Date date)
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
void RoomArr::bookings(std::string name, Date date)
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

void RoomArr::checkTicket(long unsigned int serialNumber)
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
