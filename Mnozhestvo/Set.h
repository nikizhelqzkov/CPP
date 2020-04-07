#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED
#include <iostream>

class Set
{
private:
    int *arr;
    size_t size;

public:
    Set();
    Set(int *, size_t);
    Set(const Set &);
    ~Set();
    int *getArr() const;
    size_t getSize() const;
    void setSet(const int *, size_t);
    int *begin();
    int *end();
    void print();
    bool operator()(int) const;
    bool operator!();
    Set &operator+=(int);
    Set &operator+=(Set);
    Set &operator-=(int);
    Set &operator-=(Set);
    Set &operator*=(const Set &);
    bool operator==(const Set &) const;
    bool operator!=(const Set &) const;
};
bool operator<=(const Set &, const Set &);
bool operator>=(const Set &, const Set &);
std::ostream &operator<<(std::ostream &, Set &);
#endif