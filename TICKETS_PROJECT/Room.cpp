#include "Room.h"
//#include "Date.cpp"
#include <iostream>
#include <cassert>
//#include "Client.cpp"

bool isItOkMatrix(int rows, int cols, std::vector<std::vector<Client>> m)
{
    if (rows != m.size())
        return false;
    else
    {
        for (int i = 0; i < rows; i++)
        {
            if (m[i].size() != cols)
            {
                return false;
            }
        }
        return true;
    }
}
Room::Room()
{
    this->id = 0;
    //this->name = "";-->za event
    this->rows = 0;
    this->placeOnRow = 0;
}
Room::Room(/*Date eventDate,*/ int id, const std::vector<std::vector<Client>> &place, /*std::string name,*/ int rows, int placeOnRow)
    : /*eventDate(eventDate),*/ id(id) /* name(name)*/
{
    this->setRows(rows);
    this->setCols(placeOnRow);
    assert(isItOkMatrix(this->rows, this->placeOnRow, place));
    this->matrix = place;
}
Room::~Room()
{
    //     for (int i = 0; i < this->rows; i++)
    //     {
    //         delete[] this->places[i];
    //     }
    //     delete[] this->places;
}
Room::Room(const Room &other) : /*eventDate(other.eventDate), */ id(other.id), /* name(other.name), */ rows(other.rows),
                                placeOnRow(other.placeOnRow), matrix(other.matrix)
{
}
void Room::print() const
{
    std::cout << /*"Name: " << this->name << "Date: " << this->eventDate << ",*/ "Number: " << this->id << ", Rows: " << this->rows << ", Columns: " << this->placeOnRow << "\n\n";
    for (auto vec : this->matrix)
    {
        for (auto x : vec)
        {
            x.print();
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}
// std::string Room::getName() const
// {
//     return this->name;
// }
int Room::getId() const
{
    return this->id;
}
int Room::getRows() const
{
    return this->rows;
}
std::vector<std::vector<Client>> Room::getplaces() const
{
    return this->matrix;
}
std::vector<std::vector<Client>> Room::getplaces() 
{
    return this->matrix;
}

int Room::getCols() const
{
    return this->placeOnRow;
}
// Date Room::getDate() const
// {
//     return this->eventDate;
// }
void Room::setId(int id)
{
    this->id = id;
}
// void Room::setName(std::string name)
// {
//     this->name = name;
// }
void Room::setMatrix(const std::vector<std::vector<Client>> &other)
{
    assert(isItOkMatrix(this->rows, this->placeOnRow, other));
    this->matrix = other;
}
void Room::setRows(int rows)
{
    assert(rows > 0);
   // std::cout<<rows;
    this->rows = rows;
}
void Room::setCols(int cols)
{
    assert(cols > 0);
    this->placeOnRow = cols;
}
std::ostream &operator<<(std::ostream &out, const Room &room)
{
    out /*<<"Name: "<<room.getName()<<", Date: "<<room.getDate()*/ << "Number: " << room.getId() << ", Rows: " << room.getRows() << ", Columns: " << room.getCols() << "\n\n";
    for (auto vec : room.getplaces())
    {
        for (auto x : vec)
        {
            x.print();
        }
        out << "\n";
    }
    return out;
}
Room &Room::operator=(const Room &other)
{
    if (this != &other)
    {
        id = other.id;
        this->matrix = other.matrix;
        rows = other.rows;
        placeOnRow = other.placeOnRow;
    }
    return *this;
}