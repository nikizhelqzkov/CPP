#pragma once
#include "gold.h"
#include "philosopheStone.h"
class Uravnenie
{
private:
    std::vector<Elements *> data;
    void copy(const Uravnenie &other);
    void clear();

public:
    Uravnenie() = default;
    Uravnenie(std::vector<Elements *>);
    ~Uravnenie();
    Uravnenie(const Uravnenie &other);
    Uravnenie &operator=(const Uravnenie &other);
    Elements *operator[](size_t index);
    const Elements *operator[](size_t index) const;
    std::vector<Elements *> getData() const;
    void print() const;
    void print_2() const;
    void printLikeFormula() const;
};
