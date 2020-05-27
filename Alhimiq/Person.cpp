#include "Person.h"

Person::Person(const Book &_formulas, const ElementsCountStorage &_storage) : formulas(_formulas), storage(_storage)
{
}

bool Person::isItValid()
{
    bool hasPH = false;
    size_t index = 1;
    for (int i = 0; i < formulas.getData().size(); ++i)
    {
        if (formulas[i]->getUr().getData().size() > 1)
        {
            if (formulas[i]->getEl()->getName() == "Philosopher's Stone")
            {
                hasPH = true;
                index = i;
            }
        }
    }
    if (!hasPH)
    {
        return false;
    }

    for (int i = 0; i <= index; ++i)
    {
      
        if (formulas[i]->getUr().getData().size() > 1)
        {
            for (int j = 0; j < formulas[i]->getUr().getData().size(); ++j)
            {
                bool isItHasAName = false;
                for (int stIndex = 0; stIndex < storage.getData().size(); ++stIndex)
                {
                    if (formulas[i]->getUr().getData()[j]->getName() == storage.getData()[stIndex].getName())
                    {
                        isItHasAName = true;
                        storage.setCountEl(stIndex, storage.getData()[stIndex].getCount() - 1);
                    }
                }

                if (!isItHasAName)
                {
                    return false;
                }
                else
                {
                    storage = storage.removeEl();
                }
            }
            if (i == index && formulas[i]->getEl()->getName() == "Philosopher's Stone")
            {
                return true;
            }
            CountElements elementToAdd(formulas[i]->getEl()->getName(), 1);
             
           storage+=elementToAdd;
        }
        else if (formulas[i]->getUr().getData().size() == 1)
        {

            bool isItHasAName2 = false;
            for (int stIndex = 0; stIndex < storage.getData().size(); ++stIndex)
            {
                if (formulas[i]->getUr().getData()[0]->getName() == storage.getData()[stIndex].getName())
                {
                    isItHasAName2 = true;
                    storage.setCountEl(stIndex, storage.getData()[stIndex].getCount() - 1);
                }
            }
            if (!isItHasAName2)
            {
                return false;
            }
            else
            {
                storage = storage.removeEl();
            }
            for (int j = 0; j < formulas[i]->getEl_2().size(); ++j)
            {
                CountElements elementToAdd(formulas[i]->getEl_2()[j]->getName(), 1);
                storage += elementToAdd;
            }
        }
    }
}
Person::~Person() {}

Book Person::getFormula() const
{
    return this->formulas;
}
ElementsCountStorage Person::getStorage() const
{
    return this->storage;
}