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
            if (matrix[i][j].getName() == "FREE PLACE")
            {
                std::cout << "row: " << i << ", place: " << j << ", ";
            }
        }
    }
}