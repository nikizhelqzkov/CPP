#include "formula2.h"
Formula2::Formula2(const Uravnenie &other)
{
    if (other.getData().size() == 1)
    {
        this->data = other;
        for (Elements *e : data.getData())
        {
            if (e->getName() == "Water" || e->getName() == "Earth" || e->getName() == "Fire" || e->getName() == "Air" || e->getName() == "Philosopher's Stone")
            {
                this->el.push_back(e);
                this->el.push_back(e);
            }
            else if (e->getFathers()[0] != "0")
            {
                if (e->getFathers().size() == 1)
                {
                    if (e->getFathers()[0] == "Air")
                    {

                        this->el.push_back(this->el2[3]);
                        this->el.push_back(this->el2[3]);
                    }
                    else if (e->getFathers()[0] == "Metal")
                    {
                        this->el.push_back(this->el2[4]);
                        this->el.push_back(this->el2[4]);
                    }
                }
                else if (e->getFathers().size() == 2)
                {
                    for (int i = 0; i < 2; ++i)
                    {
                        if (e->getFathers()[i] == "Earth")
                        {
                            this->el.push_back(this->el2[0]);
                        }
                        else if (e->getFathers()[i] == "Fire")
                        {
                            this->el.push_back(this->el2[1]);
                        }
                        else if (e->getFathers()[i] == "Water")
                        {
                            this->el.push_back(this->el2[2]);
                        }
                        else if (e->getFathers()[i] == "Air")
                        {
                            this->el.push_back(this->el2[3]);
                        }
                    }
                }
            }
        }
    }
}
Formula2::Formula2(const Formula2 &other)
{
    this->data = other.data;
    this->el = other.el;
}
Formula2::~Formula2()
{
}
void Formula2::print() const
{
    std::cout << "/" << this->data.getData()[0]->getName() << "\n";
    // std::cout << this->data.getData()[0]->getName() << "--> ";
    // for (int i = 0; i < this->el.size(); i++)
    // {
    //     std::cout << this->el[i]->getName() << " ";
    // }
}
void Formula2::Print() const
{
}
bool Formula2::isItValid()const
{
    return true;
}
BaseFormula *Formula2::clone() const {
    return new Formula2(*this);
}
