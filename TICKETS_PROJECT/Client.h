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
    bool reserve;
    bool buy;
    std::string note;
    std::string name;
    long unsigned int serialNumber;

public:
    Client();
    Client(int, int, Date, std::string, std::string);
    Date getDate() const;
    void read();
    void print();
    int getRow() const;
    int getCol() const;
    std::string getName() const;
    std::string getNote() const;
    void setName(std::string);
    // bool getRooms(const RoomArr &);
};

#endif