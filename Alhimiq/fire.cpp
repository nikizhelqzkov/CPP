#include "fire.h"
Fire::Fire()
{
}

Fire::~Fire()
{
}
std::vector<std::string> Fire::getEl() const
{
    return this->reactWith;
}
void Fire::print() const
{
    for (auto f : this->reactWith)
    {
        std::cout<<f<<"  ";
    }
}