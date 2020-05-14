#include "gold.h"

Gold::Gold() : Metal()
{
    reactWith = Metal::reactWith;
}

Gold::~Gold()
{
}
std::vector<std::string> Gold::getReactings() const
{
    return this->reactWith;
}
std::string Gold::getName() const
{
    return this->name;
}
void Gold::print() const
{
    for (auto g : this->reactWith)
    {
        std::cout << g << "  ";
    }
}