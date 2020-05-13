#include "gold.h"

Gold::Gold() : Metal()
{
    reactWith = Metal::reactWith;
}

Gold::~Gold()
{
}
void Gold::print() const
{
    for (auto g : this->reactWith)
    {
        std::cout<<g<<"  ";
    }
}