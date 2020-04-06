#include "Room.cpp"
//#include <iostream>
int main()
{
    Date date1;
    Date date2;

    date1.read();
    date2.read();
    Client a(1, 1, date1, "Monika");
    Client b(1, 2, date2, "Ivana");

    std::vector<std::vector<Client>> v(2, std::vector<Client>(2));
    v[0][0] = a;
    v[0][1] = b;
    v[1][0] = b;
    v[1][1] = a;
    Room club(1, v, 12,12);
    
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