#include "spirit.h"
Spirit::Spirit() : Air()
{
    reactWith = Air::reactWith;
}

Spirit::~Spirit()
{
}
std::vector<std::string> Spirit::getReactings() const
{
    return this->reactWith;
}
std::string Spirit::getName() const
{
    return this->name;
}
void Spirit::print() const
{
    for (auto s : this->reactWith)
    {
        std::cout<<s<<"  ";
    }
}
Elements *Spirit::clone() const {
    return new Spirit(*this);
}
std::vector<std::string> Spirit::getFathers() const{
    return this->father;
}