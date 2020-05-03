#ifndef EVENT_H
#define EVENT_H

#include "Room.h"
class Event : public Room
{
private:
    std::string name;
    Date eventDate;

public:
    Event();
    Event(const Date &, std::string, int, const std::vector<std::vector<Client>> &, int, int);
    Event(const Event&);
    ~Event();
    Event& operator=(const Event&);
};



#endif