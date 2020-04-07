#include "DataOfRooms.h"
#include <iostream>
RoomArr::RoomArr()
{
    this->size = this->data.size();
}
RoomArr::RoomArr(const std::vector<Room> &data, size_t size)
{
    this->data = data;
    this->size = data.size();
}
RoomArr::RoomArr(const RoomArr &other)
{
    this->data = other.data;
    this->size = other.size;
}
void RoomArr::printArr() const
{
    for (int i = 0; i < this->size; i++)
    {
        // std::cout << this->data[i];
        this->data[i].print();
    }
}
Room &RoomArr::operator[](int i)
{
    return this->data[i];
}
Room RoomArr::operator[](int i) const
{
    return this->data[i];
}
bool RoomArr::addEvent(const Room &other)
{
    bool flag = true;
    if (!this->data.empty())
    {
        this->data.resize(1);
        this->size++;
        for (int i = 0; i < this->size; i++)
        {
            if (data[i].getId() == other.getId())
            {
                return false;
            }
        }
    }
    this->data.push_back(other);
    return true;
}

 bool RoomArr::removeEvent(const Room& other){
     for (int i = 0; i < this->size; i++)
     {
         if(this->data[i].getId()==other.getId()){
             this->size--;
             this->data.erase(this->data.begin()+i);
             return true;
         }
     }
     return false;
     
 }