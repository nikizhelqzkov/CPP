#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <string>
//#include "Date.h"
#include "Client.h"
class Room
{
protected:
    int id;
    //mestata shte sa ot obekti
   // int **places;
    std::vector<std::vector<Client>> matrix;
    
    int rows;
    int placeOnRow;
//    Date eventDate;-->za event

public:
    Room();
    Room(/*Date*/ int,const std::vector<std::vector<Client>>&,/* std::string,*/int, int);
    Room(const Room &);
    ~Room();
    void print()const;
    //std::string getName()const;->za event
    int getId()const;
    int getRows()const;
    int getCols()const;
    std::vector<std::vector<Client>>getplaces()const;
    std::vector<std::vector<Client>>getplaces();
   // void setName(std::string);-->za event
    void setId(int);
    void setRows(int rows);
    void setCols(int cols);
    void setMatrix(const std::vector<std::vector<Client>>&);
    Room& operator=(const Room&);
   // Date getDate()const;-->za event
  
    //i->ti element
    //operaciq ravno
    //==
    //!=
    //busy
}; 


#endif