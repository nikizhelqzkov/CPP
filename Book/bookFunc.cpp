#include "Book.h"
#include <cassert>
#include <cstring>

Book::Book()
{
    this->number = 0;
    this->Header = nullptr;
    this->Author = nullptr;
    this->sustoqnie = 1;
}

Book::Book(int number, const char *Author, const char *Header, const int sustoqnie)
{
    this->number = number;

    assert(Author && strlen(Author) <= 24);
    this->Author = new char[strlen(Author) + 1];
    strcpy(this->Author, Author);

    //this->Author[s] = '\0';
    //size_t s = strlen(Author) + 1;

    assert(Header && strlen(Header) <= 49);
    this->Header = new char[strlen(Header) + 1];
    strcpy(this->Header, Header);

    //size_t z = strlen(Header) + 1;
    //this->Header[z] = '\0';

    assert(sustoqnie == 0 || sustoqnie == 1 || sustoqnie == 2);
    this->sustoqnie = sustoqnie;
}

Book::Book(const Book &other)
{
    this->number = other.number;

    delete[] this->Author;
    this->Author = new char[strlen(other.Author) + 1];
    strcpy(this->Author, other.Author);

    delete[] this->Header;
    this->Header = new char[strlen(other.Header) + 1];
    strcpy(this->Header, other.Header);

    this->sustoqnie = other.sustoqnie;
}

Book::~Book()
{
    delete[] Author;
    delete[] Header;
}

int Book::getNumber() const
{
    return this->number;
}

char *Book::getAuthor() const
{
    char *result = new char[strlen(this->Author) + 1];
    strcpy(result, this->Author);
    return result;
}

char *Book::getHeader() const
{
    char *result = new char[strlen(this->Header) + 1];
    strcpy(result, this->Header);
    return result;
}

void Book::setBook(int number, const char *Author, const char *Header, const int s)
{
    this->number = number;

    assert(Author && strlen(Author) <= 24);
    delete[] this->Author;
    this->Author = new char[strlen(Author) + 1];
    strcpy(this->Author, Author);

    assert(Header && strlen(Header) <= 49);
    delete[] this->Header;
    this->Header = new char[strlen(Header) + 1];
    strcpy(this->Header, Header);

    assert(sustoqnie == 0 || sustoqnie == 1 || sustoqnie == 2);
    this->sustoqnie = s;
}

int Book::getSustoqnie() const
{
    return this->sustoqnie;
}

std::ostream &operator<<(std::ostream &out, Book &book)
{
    out << "NUMBER: " << book.getNumber() << '\n';
    out << "AUTHOR: " << book.getAuthor() << '\n';
    out << "HEADER: " << book.getHeader() << '\n';
    if (book.getSustoqnie() == 0)
    {
        out << "SUSTOQNIE: "
            << "BUSY BOOK" << '\n';
    }
    else if (book.getSustoqnie() == 1)
    {
        out << "SUSTOQNIE: "
            << "FREE BOOK" << '\n';
    }
    else
    {
        out << "SUSTOQNIE: "
            << "SAMO ZA CHITALNQ" << '\n';
    }
    return out;
}
/*if (book.getSustoqnie() == 0) {
std::ostream &operator<<(std::ostream &out, const Book &book) {
out << "Book number: " << book.getNumber() << "\n"
    << "Author: " << book.getAuthor() << "\n"
    << "Title: " << book.getHeader() << "\n"
    << "Availability: " << book.getSustoqnie() << "\n";
return out;
    out << "SUSTOQNIE: "
        << "BUSY BOOK" << '\n';
} else if (book.getSustoqnie() == 1) {
    out << "SUSTOQNIE: "
        << "FREE BOOK" << '\n';
} else {
    out << "SUSTOQNIE: "
        << "SAMO ZA CHITALNQ" << '\n';
}
out << "NUMBER: " << book.getNumber() << '\n'
<< "AUTHOR: " << book.getAuthor() << '\n'
<< "HEADER: " << book.getHeader() << '\n';
}
*/

void Book::print()
{

    std::cout << "NUMBER: " << this->getNumber() << '\n';
    std::cout << "AUTHOR: " << this->getAuthor() << '\n';
    std::cout << "HEADER: " << this->getHeader() << '\n';
    if (this->getSustoqnie() == 0)
    {
        std::cout << "SUSTOQNIE: "
                  << "BUSY BOOK" << '\n';
    }
    else if (this->getSustoqnie() == 1)
    {
        std::cout << "SUSTOQNIE: "
                  << "FREE BOOK" << '\n';
    }
    else
    {
        std::cout << "SUSTOQNIE: "
                  << "SAMO ZA CHITALNQ" << '\n';
    }
}

void getData(Book *arr, int size, const char *name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].getAuthor(), name) == 0 && arr[i].getSustoqnie() == 1)
        {
            std::cout << arr[i] << "\n\n-----------------\n\n";
        }
    }
}