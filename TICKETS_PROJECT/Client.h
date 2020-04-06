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
    void print();
};

#endif