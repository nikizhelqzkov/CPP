#ifndef ROOM_H
#define ROOM_H

class Room
{
private:
    int id;
//mestata shte sa ot obekti    
    int **places;
    int rows;
    int placeOnRow;

public:
    Room();
    Room(int, int **, int, int);
    Room(const Room &);
    ~Room();
    void print() const;
    //getur
    //seturi
    //i->ti element
    //operaciq ravno
    //==
    //!=
};

class RoomArr
{
private:
    Room *arr;
    size_t size;

public:
    RoomArr();
    RoomArr(Room *, size_t);
    RoomArr(const RoomArr&);
    ~RoomArr();
    void printArr()const;
    //i-ti element
    //add event = operator + na room i proverka dali tozi nomer na staqta ne e zaet
};
#endif