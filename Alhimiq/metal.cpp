#include "metal.h"
Metal::Metal() : Earth(), Fire()
{
    reactWith = Earth::reactWith;
    size_t size = reactWith.size();
    bool isIn = false;
    for (size_t i = 0; i < Fire::reactWith.size(); i++)
    {
        isIn = false;
        for (size_t j = 0; j < size; j++)
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
}

Metal::~Metal()
{
}
void Metal::print()const{
     for (auto m : this->reactWith)
    {
        std::cout<<m<<"  ";
    }
}