#include "earth.h"
Earth::~Earth()
{
}
std::vector<std::string> Earth::getReactings() const
{
    return this->reactWith;
}
std::string Earth::getName() const
{
    return this->name;
}
void Earth::print() const
{
    for (auto e : this->reactWith)
    {
        std::cout << e << "  ";
    }
}