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
    void print();
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

class RoomArr
{
private:
    Room *arr;
    size_t size;

public:
    RoomArr();
    RoomArr(Room *, size_t);
    RoomArr(const RoomArr &);
    ~RoomArr();
    void printArr() const;
    //i-ti element
    //add event = operator + na room i proverka dali tozi nomer na staqta ne e zaet
};
#endif