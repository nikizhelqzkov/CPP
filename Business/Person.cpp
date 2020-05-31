#include "Person.h"

Person::Person()
{
    this->person_name = "";
    this->insurance_id = 0;
}
Person::Person(std::string name, int id) : person_name(name), insurance_id(id) {}
Person::~Person() {}
std::string Person::getName() const
{
    return this->person_name;
}
int Person::getId() const
{
    return this->insurance_id;
}
void Person::setName(std::string name)
{
    this->person_name = name;
}
void Person::setId(int id)
{
    this->insurance_id = id;
}