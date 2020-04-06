#include "Room.h"
#include "Date.cpp"
#include <iostream>
#include <cassert>
#include "Client.cpp"

Room::Room()
{
    this->id = 0;
    // this->places = nullptr;

    this->rows = 0;
    this->placeOnRow = 0;
}
Room::Room(int id, const std::vector<std::vector<Client>>& place, int rows, int placeOnRow)
{
    this->id = id;
    assert(rows > 0 && placeOnRow > 0);
    this->rows = rows;
    this->placeOnRow = placeOnRow;
    //     this->matrix.resize(this->rows);
    //     for (int i = 0; i < this->rows; i++)
    //     {
    //         this->matrix[i].resize(this->placeOnRow);
    //     }
    //     Client def;
    // for (int i = 0; i < this->rows; i++)
    // {
    //     for (int j = 0; j < placeOnRow; j++)
    //     {
    //         matrix[i][j] =  def;
    //     }
    this->matrix = place;

    // this->places = new int *[rows];
    // for (int i = 0; i < this->rows; i++)
    // {
    //     this->places[i] = new int[placeOnRow];

    //     for (int j = 0; j < placeOnRow; j++)
    //     {
    //         this->places[i][j] = places[i][j];
    //     }

    // }
}
Room::~Room()
{
    //     for (int i = 0; i < this->rows; i++)
    //     {
    //         delete[] this->places[i];
    //     }
    //     delete[] this->places;
}
Room::Room(const Room &other)
{
    this->id = other.id;
    this->rows = other.rows;
    this->placeOnRow = other.placeOnRow;
    this->matrix = other.matrix;
    //     this->places = new int *[this->rows];
    //     for (int i = 0; i < this->rows; i++)
    //     {
    //         this->places[i] = new int[placeOnRow];
    //         *(this->places[i]) = *(other.places[i]);
    //     }
}
void Room::print()
{
    std::cout << "Number: " << this->id << ", Rows: " << this->rows << ", Columns: " << this->placeOnRow << "\n\n";
    for (auto vec : this->matrix)
    {
        for (auto x : vec)
        {
            x.print();
        }
        std::cout << "\n";
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

int Room::getCols() const
{
    return this->placeOnRow;
}