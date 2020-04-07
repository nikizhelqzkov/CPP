#ifndef CLIENT_H
#define CLIENT_H

#include "Date.h"
#include <string>
#include "DataOfRooms.h"
class Client
{
private:
    int row;
    int col;
    Date date;
    std::string name;
    std::string note;

public:
    Client();
    Client(int, int, Date, std::string, std::string);
    std::string getName() const;
    Date getDate() const;
    void setName(const std::string &);
    void read();
    void print();
    int getRow() const;
    int getCol() const;
    bool getRooms(const RoomArr &);
};

#endif