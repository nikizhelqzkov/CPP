#include "air.h"
Air::Air()
{

}

Air::~Air()
{
    
}
void Air::print() const
{
    for (auto a : this->reactWith)
    {
        std::cout<<a<<"  ";
    }
}