#include "uravnenie.h"

void Uravnenie::copy(const Uravnenie &other)
{
    for (Elements *el : other.data)
    {
        this->data.push_back(el->clone());
    }
}

void Uravnenie::clear()
{
    for (Elements *&el : this->data)
    {
        delete el;
        el = nullptr;
    }
}

Uravnenie::Uravnenie(std::vector<Elements *> _data) : data(_data) {}
Uravnenie::Uravnenie(const Uravnenie &other)
{
    this->copy(other);
}
Uravnenie::~Uravnenie()
{
    this->clear();
}
Uravnenie &Uravnenie::operator=(const Uravnenie &other)
{
    if (this != &other)
    {
        this->clear();
        this->copy(other);
    }
    return *this;
}
Elements *Uravnenie::operator[](size_t index)
{
    return this->data[index];
}
const Elements *Uravnenie::operator[](size_t index) const
{
    return this->data[index];
}
std::vector<Elements *> Uravnenie::getData() const
{
    return this->data;
}
void Uravnenie::print() const
{
    for (Elements *el : this->data)
    {
        std::cout << el->getName() << "  ";
    }
    std::cout << std::endl;
}
void Uravnenie::print_2() const
{
    for (Elements *el : this->data)
    {
        for(auto str:el->getReactings()){
            std::cout<<str<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout << std::endl;
}
void Uravnenie::printLikeFormula() const
{

    for (size_t i = 0; i < this->data.size(); i++)
    {
        if (i == this->data.size() - 1)
        {
            std::cout << this->data[i]->getName() << " = ";
        }
        else
        {
            std::cout << this->data[i]->getName() << " + ";
        }
        }
}