#ifndef CLIENT_H
#define CLIENT_H

#include "Date.h"
#include <string>

class Client
{
private:
    int row;
    int col;
    Date date;
    std::string name;

public:
    Client();
    Client(int, int, Date, std::string);
    std::string getName() const;
    void setName(const std::string &);
    void read();
    void print();
    int getRow()const;
    int getCol()const;
};

#endif