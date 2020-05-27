#include "book.h"
void Book::copy(const Book &other)
{
    for (BaseFormula *formula : other.data)
    {
        this->data.push_back(formula->clone());
    }
}
const Book &Book::addFormula(const BaseFormula *f)
{
    if (f->isItValid())
    {
        this->data.push_back(f->clone());
    }
    return *this;
}
void Book::clear()
{
    for (BaseFormula *&f : this->data)
    {
        delete f;
        f = nullptr;
    }
}
Book::Book(std::vector<BaseFormula *> _data) : data(_data) {}
Book::Book(const Book &other)
{
    this->copy(other);
}
Book::~Book()
{
    this->clear();
}
Book &Book::operator=(const Book &other)
{
    if (this != &other)
    {
        this->clear();
        this->copy(other);
    }
    return *this;
}
BaseFormula *Book::operator[](size_t index)
{
    return this->data[index];
}
const BaseFormula *Book::operator[](size_t index) const
{
    return this->data[index];
}
std::vector<BaseFormula *> Book::getData() const
{
    return this->data;
}
void Book::print() const
{
    for (BaseFormula *f : this->data)
    {
         f->print();
         //std::cout<<"\n";
    }
    //std::cout << std::endl;
}
