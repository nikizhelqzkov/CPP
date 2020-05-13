#include "spirit.h"
Spirit::Spirit() : Air()
{
    reactWith = Air::reactWith;
}

Spirit::~Spirit()
{
}
void Spirit::print() const
{
    for (auto s : this->reactWith)
    {
        std::cout<<s<<"  ";
    }
}