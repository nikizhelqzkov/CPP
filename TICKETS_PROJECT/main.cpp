#include "Room.cpp"
//#include <iostream>
//datite da sa subota i  nedelq
int main()
{
    Date z1;
    z1.getLiveData();
    z1.print();
    Date d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;
        Client c,d,e;
        //c.read();d.read();
        e.read();
        
    std::vector<std::vector<Client>> v(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v2(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v3(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v4(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v5(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v6(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v7(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v8(7, std::vector<Client>(7));
    std::vector<std::vector<Client>> v9(7, std::vector<Client>(7));
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                v[i][j].setName("FREE PLACE");
            }
        }

  
    v[e.getRow()-1][e.getCol()-1] = e;

    // std::cout<<v[2].size();
    Room club(d1, 1, v, 7, 7);
    Room club2(d2, 1, v2, 7, 7);
    Room club3(d3, 1, v3, 7, 7);
    Room club4(d4, 1, v4, 7, 7);
    Room club5(d5, 1, v5, 7, 7);
    Room club6(d6, 1, v6, 7, 7);
    Room club7(d7, 1, v7, 7, 7);
    Room club8(d8, 1, v8, 7, 7);
    Room club9(d9, 1, v9, 7, 7);

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