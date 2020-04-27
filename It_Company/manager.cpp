#include "manager.h"

Manager::Manager(const char *_name, size_t _workExp, size_t _countManage)
    : Employ(_name, _workExp), countManage(_countManage)
{
}
Manager::Manager(const Manager &other) : Employ(other), countManage(other.countManage) {}

Manager &Manager::operator=(const Manager &other)
{
    if (this != &other)
    {
        Employ::operator=(other);
        countManage = other.countManage;
    }

    return *this;
}
size_t Manager::getCountManage() const
{
    return countManage;
}
void Manager::printOwn() const
{
    std::cout << countManage << std::endl;
}
Employ **Manager::addEmploy(Employ *arr[], size_t size)
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
Employ **Manager::removeEmploy(Employ *arr[], size_t size)
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