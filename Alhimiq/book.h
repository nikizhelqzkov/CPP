#pragma once
#include "formula.h"
#include "formula2.h"
class Book
{
private:
    std::vector<BaseFormula *> data{};
    void copy(const Book &other);
    void clear();

public:
    Book() = default;
    Book(std::vector<BaseFormula *>);
    ~Book();
    const Book &addFormula(const BaseFormula *);
    Book(const Book &);
    Book &operator=(const Book &other);
    BaseFormula *operator[](size_t index);
    const BaseFormula *operator[](size_t index) const;
    std::vector<BaseFormula *> getData() const;
    void print() const;
};
