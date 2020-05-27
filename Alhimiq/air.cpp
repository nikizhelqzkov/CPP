#include "air.h"

Air::~Air()
{
}
void Air::print() const
{
    for (auto a : this->reactWith)
    {
        std::cout << a << "  ";
    }
}
std::vector<std::string> Air::getReactings() const
{
    return this->reactWith;
}
std::string Air::getName() const
{
    return this->name;
}
Elements *Air::clone() const
{
    return new Air(*this);
}
std::vector<std::string> Air::getFathers() const{
    return this->father;
}
Air* Air::read(std::istream& in){
    
    return new Air;
}
