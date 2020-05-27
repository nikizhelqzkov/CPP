#include "ElementsCountStorage.h"

ElementsCountStorage::ElementsCountStorage(std::vector<CountElements> _data) : data(_data) {}
ElementsCountStorage::~ElementsCountStorage() {}
ElementsCountStorage::ElementsCountStorage(const ElementsCountStorage &other)
{
    this->data = other.data;
}
ElementsCountStorage &ElementsCountStorage::operator=(const ElementsCountStorage &other)
{
    if (this != &other)
    {
        this->data = other.data;
    }
    return *this;
}
ElementsCountStorage &ElementsCountStorage::addEl(const CountElements &other)
{
    bool isItIn = false;
    for (CountElements d : data)
    {
        if (d.getName() == other.getName())
        {
            isItIn = true;
            d.setCount(d.getCount() + 1);
            return *this;
        }
    }
    if (!isItIn)
    {
        this->data.push_back(other);
        return *this;
    }
}
ElementsCountStorage &ElementsCountStorage::removeEl()
{
    for (int i = 0; i < data.size(); ++i)
    {
        if (data[i].getIsItEmpty())
        {
            data.erase(data.begin()+i);
        }
    }
    return *this;
}
