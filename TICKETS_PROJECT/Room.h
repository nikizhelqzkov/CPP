#ifndef ROOM_H
#define ROOM_H

class Room
{
private:
    int id;
    int **places;
    int rows;
    int placeOnRow;

public:
    Room();
    Room(int&, const int **,int&, int&);
    Room(const Room &);
    ~Room();
    void print()const;
};

#endif