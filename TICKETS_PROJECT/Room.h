#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <string>
#include "Date.h"
#include "Client.h"
class Room
{
private:
    int id;
    //mestata shte sa ot obekti
   // int **places;
    std::vector<std::vector<Client>> matrix;
    int rows;
    int placeOnRow;

public:
    Room();
    Room(int,const std::vector<std::vector<Client>>&, int, int);
    Room(const Room &);
    ~Room();
    void print()const;
    int getId()const;
    int getRows()const;
    int getCols()const;
    std::vector<std::vector<Client>>getplaces()const;
    void setId(int);
    void setRows(int rows);
    void setCols(int cols);
    void setMatrix(const std::vector<std::vector<Client>>&);
  
    //i->ti element
    //operaciq ravno
    //==
    //!=
    //busy
}; 


#endif