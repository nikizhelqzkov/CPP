#include "Person.h"

Person::Person()
{
    this->person_name = "";
    this->insurance_id = 0;
    this->hasPayer = false;
}
Person::Person(std::string name, bool hasPayer) : person_name(name), hasPayer(hasPayer) {}
Person::~Person() {}
std::string Person::getName() const
{
    return this->person_name;
}
int Person::getId() const
{
    return this->insurance_id;
}
bool Person::getHasPayer() const
{
    return this->hasPayer;
}

void Person::setName(std::string name)
{
    this->person_name = name;
}
void Person::setId(int id)
{
    this->insurance_id = id;
}