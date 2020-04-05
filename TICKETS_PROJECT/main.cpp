#include "Date.cpp"
#include "Room.cpp"

int main()
{
    // Date date(25,06,2000);
    // date.print();
    int id = 3;
    int a[3][10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                    21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int row = 3;
    int col = 10;
    Room A(id,a,row,col);
}