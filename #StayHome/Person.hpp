#include "Person.h"
#include <iostream>
#include <cstring>
#include <cassert>

bool IsItEmail(const char *email)
{
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            return true;
        }
    }
    return false;
}
bool IsItLeterUserName(const char *name)
{
    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] >= '0' && name[i] <= '9')
        {
            return false;
        }
    }
    return true;
}

// Person::Person()
// {
//     this->name = nullptr;
//     this->years = 0;
//     this->email = nullptr;
//     this->id = 0;
// }
Person::Person(const char *name = nullptr, int years = 0, const char *email = nullptr, int id = 0) : id(id)
{

    assert(name && IsItLeterUserName(name));

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    assert(years > 0 && years <= 90);
    this->years = years;
    if (!IsItEmail(email))
    {
        this->email = "";
    }
    else
    {
        assert(strlen(email) <= 100);
        this->email = new char[strlen(email) + 1];
        strcpy(this->email, email);
    }
}
Person::Person(const Person &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->years = years;
    this->email = new char[strlen(other.email) + 1];
    strcpy(this->email, other.email);
    this->id = other.id;
}
Person::~Person(){
    delete[]this->name;
    delete[]this->email;
}
void Person::setName(const char *name)
{

    assert(name && IsItLeterUserName(name));
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
void Person::setEmail(const char *email)
{
    if (!IsItEmail(email))
    {
        this->email = "";
    }
    else
    {
        assert(strlen(email) <= 100);
        delete[] this->email;
        this->email = new char[strlen(email) + 1];
        strcpy(this->email, email);
    }
}
void Person::setId(int id)
{
    this->id = id;
}
void Person::setYears(int years)
{
    assert(years > 0 && years <= 90);
    this->years = years;
}
void Person::setPerson(const char *name, int years, const char *email, int id)
{
    this->setName(name);
    this->setYears(years);
    this->setEmail(email);
    this->setId(id);
}
Person &Person::operator=(const Person &other)
{
    if (this != &other)
    {
        this->setPerson(other.name, other.years, other.email, other.id);
    }
    return *this;
}
char *Person::getName() const
{
    return this->name;
}
int Person::getYears() const
{
    return this->years;
}
char *Person::getEmail() const
{
    return this->email;
}
int Person::getId() const
{
    return this->id;
}
void Person::profile_info(const char *name) const
{
    if (strcmp(this->name,name)==0)
    {
        std::cout << "PERSON NAME: " << this->name << ", ";
        if (years <= 0)
        {
            std::cout << "YEARS: UNKNOWN, ";
        }
        else
        {
            std::cout << "YEARS: " << this->years << ", ";
        }

        if (this->email == nullptr || this->email == "")
        {
            std::cout << "EMAIL: UNKNOWN, ";
        }
        else
        {
            std::cout << "EMAIL: " << this->email << ", ";
        }
        std::cout << "ID: " << this->id << "\n";
    }
}
