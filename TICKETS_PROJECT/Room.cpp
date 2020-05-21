#include "Room.h"
#include <iostream>
#include <cassert>

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
    this->rows = 0;
    this->placeOnRow = 0;
}
Room::Room( int id, const std::vector<std::vector<Client>> &place, /*std::string name,*/ int rows, int placeOnRow)
    :  id(id)
{
    this->setRows(rows);
    this->setCols(placeOnRow);
    assert(isItOkMatrix(this->rows, this->placeOnRow, place));
    this->matrix = place;
}
Room::~Room()
{
}
Room::Room(const Room &other) :  id(other.id),rows(other.rows),
                                placeOnRow(other.placeOnRow), matrix(other.matrix)
{
}
void Room::print() const
{
    std::cout <<  "Number: " << this->id << ", Rows: " << this->rows << ", Columns: " << this->placeOnRow << "\n\n";
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
void Room::print(std::ostream& out) const
{
    out <<this->id<<" "<< this->rows << " " << this->placeOnRow << "\n";
    for (auto vec : this->matrix)
    {
        for (auto x : vec)
        {
            x.print(out);
            out << "\n";
        }
        
    }
}

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

void Room::setId(int id)
{
    this->id = id;
}

void Room::setMatrix(const std::vector<std::vector<Client>> &other)
{
    assert(isItOkMatrix(this->rows, this->placeOnRow, other));
    this->matrix = other;
}
void Room::setRows(int rows)
{
    assert(rows > 0);
   
    this->rows = rows;
}
void Room::setCols(int cols)
{
    assert(cols > 0);
    this->placeOnRow = cols;
}
std::ostream &operator<<(std::ostream &out, const Room &room)
{
    out << "Number: " << room.getId() << ", Rows: " << room.getRows() << ", Columns: " << room.getCols() << "\n\n";
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
void Room::remove()
{
    this->id = 0;
    this->rows = 0;
    this->placeOnRow = 0;
}