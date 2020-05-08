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
RoomArr::~RoomArr(){
    
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
        this->data.resize(1);
        this->size++;
        for (int i = 0; i < this->size; i++)
        {
            if (data[i].getName() == other.getName() && data[i].getDate() == other.getDate())
            {
                std::cout << "ON THIS DATE THAT EVENT IS SAVED\n";
                return *this;
            }
        }
    }
    this->data.push_back(other);
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
    std::cout << "Free seats in " << name << " on " << date << "\n";
    for (int i = 0; i < this->data.size(); i++)
    {
        if (data[i].getName() == name && data[i].getDate() == date)
        {
            data[i].printFreeSeats();
        }
    }
}