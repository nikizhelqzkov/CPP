#include "water.h"

Water::Water(/* args */)
{
}

Water::~Water()
{
}
void Water::print() const
{
    for (auto w : this->reactWith)
    {
        std::cout<<w<<"  ";
    }
}