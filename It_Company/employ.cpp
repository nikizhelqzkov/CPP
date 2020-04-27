#include "employ.h"
Employ::Employ(const char *name, size_t workExp) : name(nullptr), workExp(workExp)
{
    this->setName(name);
}
Employ::Employ(const Employ &other) : Employ(other.name, other.workExp)
{
    this->setName(other.name);
}
Employ &Employ::operator=(const Employ &other)
{
    if (this != &other)
    {
        this->setName(other.name);
        this->setWorkExp(other.workExp);
    }
    return *this;
}
Employ::~Employ()
{
    delete[] name;
    name = nullptr;
}
void Employ::setName(const char *_name)
{
    assert(_name);
    delete[] name;
    size_t size = strlen(_name);
    name = new char[size + 1];
    strcpy(name, _name);
}
void Employ::setWorkExp(size_t _workExp)
{
    workExp = _workExp;
}
const char *Employ::getName() const
{
    return name;
}
size_t Employ::getWorkExp() const
{
    return workExp;
}
void Employ::print() const
{
    std::cout << this->name << " " << this->workExp << " ";
    printOwn();
}
Employ **Employ::removeEmploy(Employ *arr[], size_t size) {}
