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
