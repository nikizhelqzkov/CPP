#include "Playlist.cpp"
#include<iostream>
int main()
{

    Song A("KELESH", "TEDI ALEKSANDROVA ft. DJ DENY", "PAYNER LIVE 4K", 208);
    Song B("SARTSE MOE", "TEDI ALEKSANDROVA & EMRAH", "PAYNER VIDEOCLIPS 4K", 235);
    Song C("SARTSE MOE", "TEDI ALEKSANDROVA & EMRAH", "PAYNER VIDEOCLIPS 4K", 235);
    Song D("SARTSE MOE", "TEDI ALEKSANDROVA & EMRAH", "PAYNER VIDEOCLIPS 4K", 235);
    Song E("MEFA BOMBA", "SINAN", "FEN TV VIDEOCLIPS", 233);

    //swap(a,b);
    //std::cout<<a.getName();
    Song *arr = new Song[5];
    arr[0] = A;
    arr[1] = B;
    arr[2] = C;
    arr[3] = D;
    arr[4] = E;
    Playlist p("CHALGA HITS 2020", arr, 5);
   

    //sortPlaylistViaAuthor(p);
    sortPlaylistViaName(p);
     //sortPlaylistViaTime(p);
    printWithLimit(p, 2000);
    //std::cout<<p.getArr()[0].getAuthor();
    delete[]arr;
    return 0;
}