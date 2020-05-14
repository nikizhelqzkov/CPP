#include "energy.h"
Energy::Energy() : Water(), Air()
{
    reactWith = Water::reactWith;
    size_t size = reactWith.size();
    bool isIn = false;
    for (size_t i = 0; i < Air::reactWith.size(); i++)
    {
        isIn = false;
        for (size_t j = 0; j < size; j++)
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