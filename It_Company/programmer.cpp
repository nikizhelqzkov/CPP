#include "programmer.h"
Programmer::Programmer(const char *_name, size_t _workExp, bool _knowCPP, bool _knowCS)
    : Employ(_name, _workExp), knowCPP(_knowCPP), knowCS(_knowCS)
{
}
Programmer::Programmer(const Programmer &other) : Employ(other), knowCPP(other.knowCPP), knowCS(knowCS) {}

Programmer &Programmer::operator=(const Programmer &other)
{
    if (this != &other)
    {
        Employ::operator=(other);
        this->knowCPP = other.knowCPP;
        this->knowCS = other.knowCS;
    }

    return *this;
}
bool Programmer::getKnowCPP() const
{
    return knowCPP;
}
bool Programmer::getKnowCS() const
{
    return knowCS;
}
void Programmer::printOwn() const
{
    std::cout << knowCPP << " " << knowCS << std::endl;
}
Employ **Programmer::addEmploy(Employ *arr[], size_t size)
{
    Employ **buffer;
    buffer = new Employ *[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        buffer[i] = arr[i];
    }
    buffer[size] = this;

    return buffer;
}
Employ **Programmer::removeEmploy(Employ *arr[], size_t size)
{
    Employ **buffer;
    bool flag = false;
    buffer = new Employ *[size - 1];
    if (strcmp(this->getName(), arr[size - 1]->getName()) == 0 && arr[size - 1]->getWorkExp() == this->getWorkExp())
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            buffer[i] = arr[i];
        }
        return buffer;
    }
    else
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            if (strcmp(this->getName(), arr[i]->getName()) == 0 && arr[i]->getWorkExp() == this->getWorkExp())
            {
                flag = true;
                for (size_t j = i + 1; j < size; j++)
                {
                    arr[j - 1] = arr[j];
                }
                break;
            }
        }
        if (flag)
        {
            for (size_t i = 0; i < size - 1; i++)
            {
                buffer[i] = arr[i];
            }
            return buffer;
        }
        else
        {
            for (size_t i = 0; i < size; i++)
            {
                buffer[i] = arr[i];
            }
            return buffer;
        }
    }
}