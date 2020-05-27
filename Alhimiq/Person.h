#pragma once
#include "ElementsCountStorage.h"
#include "book.h"

class Person
{
private:
    Book formulas{};
    ElementsCountStorage storage;

public:
    Person() = default;
    Person(const Book &, const ElementsCountStorage &);

    bool isItValid();
    ~Person();

    Book getFormula() const;
    ElementsCountStorage getStorage() const;
    void setStorage(ElementsCountStorage);
};
