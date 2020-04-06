#include "Room.cpp"
//#include <iostream>

int main()
{
   

    Client c,d,e;
    c.read();d.read();
    e.read();

    std::vector<std::vector<Client>> v(7, std::vector<Client>(7));
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            v[i][j].setName("FREE PLACE");
        }
    }

v[c.getRow()-1][c.getCol()-1] = c;
v[d.getRow()-1][d.getCol()-1] = d;
v[e.getRow()-1][e.getCol()-1] = e;

// std::cout<<v[2].size();
Room club(1, v, 7,7);

club.print();
//  Date date(25,06,2000);
//  date.print();
// size_t id = 3;
//int **a = new int *[3];

// int row = 3;
// int col = 2;
// int counter = 1;
// for (int i = 0; i < row; ++i)
// {
//     a[i] = new int[col];
// }
// for (int i = 0; i < row; ++i)
// {
//     for (int j = 0; j < col; ++j)
//     {
//         std::cin>>a[i][j];
//     }
// }

// Room A(3, a, row, col);

// A.print();

// for (size_t i = 0; i < row; i++)
// {
//     delete[] a[i];
// }
// delete[] a;

return 0;
}