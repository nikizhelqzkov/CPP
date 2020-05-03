#ifndef CLIENT_H
#define CLIENT_H

#include "Date.h"
#include <string>
//#include "DataOfRooms.h"
class Client
{
private:
    int row;
    int col;
    Date date;
   
    std::string note;

public:
    Client();
    Client(int, int, Date, std::string);
    Date getDate() const;
    void read();
    void print();
    int getRow() const;
    int getCol() const;
   // bool getRooms(const RoomArr &);
};

#endif