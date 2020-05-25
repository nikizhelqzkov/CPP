#include "stone.h"
Stone::Stone() : Fire(), Water()
{
    reactWith = Fire::reactWith;
    size_t size = reactWith.size();
    bool isIn = false;
    for (size_t i = 0; i < Water::reactWith.size(); i++)
    {
        isIn = false;
        for (size_t j = 0; j < size; j++)
        {
            if (reactWith[j] == Water::reactWith[i])
            {
                isIn = true;
            }
        }
        if (!isIn)
        {
            reactWith.push_back(Water::reactWith[i]);
        }
    }
}
std::vector<std::string> Stone::getReactings() const
{
    return this->reactWith;
}
std::string Stone::getName() const
{
    return this->name;
}

Stone::~Stone()
{
}
void Stone::print() const
{
    for (auto s : this->reactWith)
    {
        std::cout<<s<<"  ";
    }
}
Elements *Stone::clone() const {
    return new Stone(*this);
}
std::vector<std::string> Stone::getFathers() const{
    return this->father;
}
