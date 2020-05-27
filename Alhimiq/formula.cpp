#include "formula.h"
Formula::Formula(const Uravnenie &_ur, Elements *_el) : ur(_ur), elem(_el) {}
Formula::Formula(const Formula &other) : Formula(other.ur, other.elem) {}

Formula::~Formula()
{
}
void Formula::print() const
{
    this->ur.printLikeFormula();
    std::cout << this->elem->getName() << "\n";
}
bool Formula::isItValid() const
{
    bool v = false, v3 = false, v4 = false, v2 = false;
    for (int k = 0; k < ur.getData().size() - 1; k++)
    {
        v = false;
        v3 = false;
        if (ur[k]->getFathers()[0] == "0")
        {

            for (int z = k + 1; z < ur.getData().size(); z++)
            {
                for (int i = 0; i < ur[k]->getReactings().size(); i++)
                {
                    if (ur[z]->getFathers()[0] == "0")
                    {

                        if (ur[k]->getReactings()[i] == ur[z]->getName())
                        {
                            for (int j = 0; j < ur[z]->getReactings().size(); j++)
                            {
                                if (ur[z]->getReactings()[j] == ur[k]->getName())
                                {

                                    v = true;
                                }
                            }
                        }
                    }
                    else
                    {
                        v = true;
                    }
                }
                if (v)
                {
                    v2 = v;
                }
                if (!v)
                    return false;
            }
        }
        else
        {
            for (int z = k + 1; z < ur.getData().size(); z++)
            {
                for (int i = 0; i < ur[k]->getReactings().size(); i++)
                {

                    if (ur[z]->getFathers()[0] == "0")
                    {
                        for (int j = 0; j < ur[k]->getReactings().size(); j++)
                        {
                            if (ur[z]->getName() == ur[k]->getReactings()[j])
                            {

                                v3 = true;
                            }
                        }
                    }
                    else
                    {
                        v3 = true;
                    }
                }
                if (v3)
                {
                    v4 = v3;
                }
                if (!v3)
                    return false;
            }
        }
    }
    bool val = v4 || v2;
    return val;
}
BaseFormula *Formula::clone() const
{
    return new Formula(*this);
}
Uravnenie Formula::getUr() const
{
    return this->ur;
}
 Elements* Formula::getEl()const{
     return this->elem;
 }
 std::vector<Elements *>Formula:: getEl_2() const{
     return this->el_2;
 }
