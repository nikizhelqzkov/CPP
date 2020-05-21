#include "Event.h"
#include <iostream>
Event::Event() : Room()
{
    eventDate = eventDate.getLiveData();
    this->name = "";
}
Event::Event(const Date &eventDate, std::string name, int id, const std::vector<std::vector<Client>> &place, int rows, int placeOnRow)
    : Room(id, place, rows, placeOnRow), eventDate(eventDate), name(name) {}
Event::Event(const Event &other) : Room(other), eventDate(other.eventDate), name(other.name) {}
Event::~Event() {}
Event &Event::operator=(const Event &other)
{
    if (this != &other)
    {
        eventDate = other.eventDate;
        name = other.name;
        id = other.id;
        this->matrix = other.matrix;
        rows = other.rows;
        placeOnRow = other.placeOnRow;
    }
    return *this;
}
std::string Event::getName() const
{
    return name;
}
Date Event::getDate() const
{
    return eventDate;
}
void Event::setName(std::string _name)
{
    name = _name;
}
void Event::setDate(Date date)
{
    eventDate = date;
}
void Event::printFreeSeats()
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j].getName() == "FREE" || matrix[i][j].getName() == "" || matrix[i][j].getReserve() == true)
            {
                std::cout << "row: " << i + 1 << ", place: " << j + 1 << " \n";
            }
        }
    }
}
bool Event::reserveFreeSeats()
{
    bool flag = false;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j].getReserve() == true)
            {
                flag = true;
                std::cout << "row: " << i + 1 << ", place: " << j + 1 << " \n";
            }
        }
    }
    return flag;
}
bool Event::bought()
{
    bool flag = false;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j].getBuy() == true)
            {
                flag = true;
                std::cout << "row: " << i + 1 << ", place: " << j + 1 << " \n";
            }
        }
    }
    return flag;
}
bool Event::checkCode(long unsigned int serialNumber)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j].getTicket() == serialNumber)
            {
                std::cout<<"\n\nEvent name: "<<this->name<<"\n";
                matrix[i][j].checkCode();
                return true;
            }
        }
    }
    return false;
}
Event &Event::unbook(int row, int col)
{
    if (matrix[row - 1][col - 1].getReserve() == false)
    {
        std::cout << "That ticket is not reserved\n";
        return *this;
    }
    matrix[row - 1][col - 1] = matrix[row - 1][col - 1].remove();
    return *this;
}
void Event::Remove()
{
    Room::remove();
    eventDate = eventDate.getLiveData();
    this->name = "";
}
void Event::Print()
{
    std::cout << this->name << ", " << this->eventDate << " , ";
    Room::print();
}
void Event::Print(std::ostream &out) const
{
    out << this->name << " " << this->eventDate;
    Room::print(out);
}
