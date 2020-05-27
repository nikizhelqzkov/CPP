#include "countElements.h"
CountElements::CountElements(std::string name, int count) : name(name), count(count)
{
}
CountElements::CountElements(const CountElements &other)
{
    this->name = other.name;
    this->count = other.count;
}
CountElements &CountElements::operator=(const CountElements &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->count = other.count;
    }
    return *this;
}
CountElements::~CountElements()
{
}
std::string CountElements::getName() const
{
    return this->name;
}
int CountElements::getCount() const
{
    return this->count;
}
void CountElements::setCount(int _count)
{
    this->count = _count;
}
bool CountElements::isItEmpty()
{
    return count <= 0;
}
bool CountElements::getIsItEmpty()
{
    return this->isItEmpty();
}
