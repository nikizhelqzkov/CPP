#include "earth.h"
Earth::~Earth()
{
}
std::vector<std::string> Earth::getReactings() const
{
    return this->reactWith;
}
std::string Earth::getName() const
{
    return this->name;
}
void Earth::print() const
{
    for (auto e : this->reactWith)
    {
        std::cout << e << "  ";
    }
}
Elements *Earth::clone() const {
    return new Earth(*this);
}
std::vector<std::string> Earth::getFathers() const{
    return this->father;
}