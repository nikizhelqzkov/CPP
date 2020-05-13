#include "earth.h"
Earth::Earth()
{
}

Earth::~Earth()
{
}
void Earth::print() const
{
    for (auto e : this->reactWith)
    {
        std::cout<<e<<"  ";
    }
}