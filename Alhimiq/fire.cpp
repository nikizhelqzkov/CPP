#include "fire.h"

Fire::~Fire()
{
}

std::vector<std::string> Fire::getReactings() const
{
    return this->reactWith;
}
std::string Fire::getName() const
{
    return this->name;
}
void Fire::print() const
{
    for (auto f : this->reactWith)
    {
        std::cout << f << "  ";
    }
}
Elements *Fire::clone() const {
    return new Fire(*this);
}
std::vector<std::string> Fire::getFathers() const{
    return this->father;
}