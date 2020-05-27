#include "philosopheStone.h"
PS::PS() : Earth(), Fire(), Water(), Air()
{
    reactWith = Earth::reactWith;
    size_t size = reactWith.size();
    bool isIn = false;
    for (size_t i = 0; i < Fire::reactWith.size(); i++)
    {
        isIn = false;
        for (size_t j = 0; j < this->reactWith.size(); j++)
        {
            if (reactWith[j] == Fire::reactWith[i])
            {
                isIn = true;
            }
        }
        if (!isIn)
        {
            reactWith.push_back(Fire::reactWith[i]);
        }
    }
    for (size_t i = 0; i < Water::reactWith.size(); i++)
    {
        isIn = false;
        for (size_t j = 0; j < this->reactWith.size(); j++)
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
    for (size_t i = 0; i < Air::reactWith.size(); i++)
    {
        isIn = false;
        for (size_t j = 0; j < this->reactWith.size(); j++)
        {
            if (reactWith[j] == Air::reactWith[i])
            {
                isIn = true;
            }
        }
        if (!isIn)
        {
            reactWith.push_back(Air::reactWith[i]);
        }
    }
}

PS::~PS()
{
}
std::vector<std::string> PS::getReactings() const
{
    return this->reactWith;
}
std::string PS::getName() const
{
    return this->name;
}
void PS::print() const
{
    for (auto ps : this->reactWith)
    {
        std::cout << ps << "  ";
    }
}
Elements *PS::clone() const
{
    return new PS(*this);
}
std::vector<std::string> PS::getFathers() const
{
    return this->father;
}
PS *PS::read(std::istream &in)
{
    return new PS;
}