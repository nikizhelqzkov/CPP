#include "Event.h"

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