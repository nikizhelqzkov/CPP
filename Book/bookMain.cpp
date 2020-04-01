#include <iostream>

#include "bookFunc.cpp"




int main()
{
    Book a(20, "Don", "Maikati", 1);
    Book b(21, "Don", "Maikati2", 1);
    Book c(12, "Don", "Maikati3", 0);
    Book arr[3];
    arr[0]=a;
    arr[1]=b;
    arr[2]=c;

    getData(arr, 3,"Don");

    for (int i = 0; i < 3; i++)
    {
        //arr[i].print();
        std::cout << std::endl;
    }

    return 0;
}



/*std::ostream &operator<<(std::ostream &out, Book &book) {
    out << "Book number: " << book.getNumber() << "\n"
        << "Author: " << book.getAuthor() << "\n"
        << "Title: " << book.getHeader() << "\n"
        << "Availability: " << book.getSustoqnie() << "\n";
    return out;
}*/