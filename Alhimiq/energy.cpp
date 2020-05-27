#include "energy.h"
Energy::Energy() : Water(), Air()
{
    reactWith = Water::reactWith;
    size_t size = reactWith.size();
    bool isIn = false;
    for (size_t i = 0; i < Energy::reactWith.size(); i++)
    {
        isIn = false;
        for (size_t j = 0; j < size; j++)
        {
            if (reactWith[j] == Energy::reactWith[i])
            {
                isIn = true;
            }
        }
        if (!isIn)
        {
            reactWith.push_back(Energy::reactWith[i]);
        }
    }
}

Energy::~Energy()
{
}
std::vector<std::string> Energy::getReactings() const
{
    return this->reactWith;
}
std::string Energy::getName() const
{
    return this->name;
}
void Energy::print() const
{
    for (auto e : this->reactWith)
    {
        std::cout << e << "  ";
    }
}
Elements *Energy::clone() const
{
    return new Energy(*this);
}
std::vector<std::string> Energy::getFathers() const
{
    return this->father;
}
Energy *Energy::read(std::istream &in)
{
    return new Energy;
}