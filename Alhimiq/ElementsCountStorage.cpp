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
ElementsCountStorage &ElementsCountStorage::operator+=(const CountElements &other)
{
    bool isItIn = false;
    int index = 0;
    for (int i = 0; i < data.size(); ++i)
    {
        if (data[i].getName() == other.getName())
        {
            isItIn = true;
            index = i;
            //  d.setCount(d.getCount() + 1);
        }
    }
    if (isItIn)
    {
        this->setCountEl(index, data[index].getCount() + 1);
        return *this;
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
            data.erase(data.begin() + i);
        }
    }
    return *this;
}
std::vector<CountElements> ElementsCountStorage::getData() const
{
    return this->data;
}

void ElementsCountStorage::setCountEl(int pos, int count)
{
    this->data[pos].setCount(count);
}