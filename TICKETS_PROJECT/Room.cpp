#include "Room.h"
#include <iostream>
#include <cassert>
Room::Room()
{
    this->id = 0;
    this->places = nullptr;
    this->rows = 0;
    this->placeOnRow = 0;
}
Room::Room(int id, int **places, int rows, int placeOnRow)
{
    this->id = id;
    assert(rows > 0 && placeOnRow > 0);
    this->rows = rows;
    this->placeOnRow = placeOnRow;
    this->places = new int *[rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->places[i] = new int[placeOnRow];

        for (int j = 0; j < placeOnRow; j++)
        {
            this->places[i][j] = places[i][j];
        }
        
    }
}
Room::~Room()
{
    for (int i = 0; i < this->rows; i++)
    {
        delete[] this->places[i];
    }
    delete[] this->places;
}
Room::Room(const Room &other)
{
    this->id = other.id;
    this->rows = other.rows;
    this->placeOnRow = other.placeOnRow;
    this->places = new int *[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->places[i] = new int[placeOnRow];
        *(this->places[i]) = *(other.places[i]);
    }
}
void Room::print() const
{
    std::cout << "Number: " << this->id << ", Rows: " << this->rows << ", Columns: " << this->placeOnRow << "\n\n";
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->placeOnRow; j++)
        {
            std::cout << this->places[i][j] << ", ";
        }
        std::cout << std::endl;
    }
}