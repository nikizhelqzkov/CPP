#include "Room.cpp"
#include <ctime>
//#include <iostream>
//datite da sa subota i  nedelq
void readTORoom(Client &c, std::vector<std::vector<Client>>& v)
{
    c.read();
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            v[i][j].setName("FREE PLACE");
        }
    }

    v[c.getRow() - 1][c.getCol() - 1] = c;
}
int main()
{
    srand(time(0));
    Date z1;
    z1.getLiveData();
    z1.print();
    std::cout << std::endl;
    Date d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;
    Client c, d, e;
    //c.read();d.read();
   // e.read();

    std::vector<std::vector<Client>> v(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v2(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v3(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v4(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v5(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v6(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v7(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v8(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v9(7, std::vector<Client>(7));
    readTORoom(e,v);
    // for (int i = 0; i < v.size(); i++)
    // {
    //     for (int j = 0; j < v[i].size(); j++)
    //     {
    //         v[i][j].setName("FREE PLACE");
    //     }
    // }

    // v[e.getRow() - 1][e.getCol() - 1] = e;

    // std::cout<<v[2].size();

    Room club(rand() % 100, v, 7, 7);
    Room club2(rand() % 100, v2, 7, 7);
    Room club3(rand() % 100, v3, 7, 7);
    Room club4(rand() % 100, v4, 7, 7);
    Room club5(rand() % 100, v5, 7, 7);
    Room club6(rand() % 100, v6, 7, 7);
    Room club7(rand() % 100, v7, 7, 7);
    Room club8(rand() % 100, v8, 7, 7);
    Room club9(rand() % 100, v9, 7, 7);

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