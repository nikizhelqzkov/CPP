#ifndef __BOOK_H_
#define __BOOK_H_

#include<iostream>
/*
struct sustoqniq
{
    int zaChitalnq = 2;
    int buzy = 0;
    int free = 1;
};
*/
class Book
{
private:
    int number;
    char *Author;
    char *Header;
    int sustoqnie;

public:
    Book();
    Book(int, const char *, const char *, const int);
    Book(const Book&);
    ~Book();

    int getNumber() const;
    char *getAuthor() const;
    char *getHeader() const;
    int getSustoqnie()const;

    void setBook(int, const char *, const char *, const int);
    bool operator==(const char*);
    void print();
};

std::ostream& operator <<(std::ostream&,Book&);

#endif
