#include "water.h"

Water::~Water()
{
}
std::vector<std::string> Water::getReactings() const
{
    return this->reactWith;
}
std::string Water::getName() const
{
    return this->name;
}
void Water::print() const
{
    for (auto w : this->reactWith)
    {
        std::cout << w << "  ";
    }
}
Elements *Water::clone() const
{
    return new Water(*this);
}
std::vector<std::string> Water::getFathers() const
{
    return this->father;
}
Water *Water::read(std::istream &in)
{
    return new Water;
}