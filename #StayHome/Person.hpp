#include "Person.h"
#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>

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

Person::Person()
{
    this->name = nullptr;
    this->years = 0;
    this->email = nullptr;
    this->id = 0;
}

Person::Person(const char *name, int years, const char *email, int id) : id(id)
{

    assert(name && IsItLeterUserName(name));

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    assert(years > 0 && years <= 90);
    this->years = years;
    if (!IsItEmail(email))
    {

        this->email = "\0";
    }
    else
    {
        assert(strlen(email) <= 100);
        this->email = new char[strlen(email) + 1];
        strcpy(this->email, email);
    }
}
Person::Person(const char *name, const char *email, int id) : id(id)
{
    this->years = 0;
    assert(name && IsItLeterUserName(name));

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    if (!IsItEmail(email))
    {
        this->email = "\0";
    }
    else
    {
        assert(strlen(email) <= 100);
        this->email = new char[strlen(email) + 1];
        strcpy(this->email, email);
    }
}
Person::Person(const char *name, int id) : id(id)
{
    this->email = "\0";
    this->years = 0;
    assert(name && IsItLeterUserName(name));

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
Person::Person(const char *name, int years, int id) : id(id)
{
    this->email = "\0";
    assert(name && IsItLeterUserName(name));

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    assert(years > 0 && years <= 90);
    this->years = years;
}
Person::Person(const Person &other) : years(other.years), id(other.id)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    if (other.years)
        this->years = other.years;
    if (other.email)
    {
        this->email = new char[strlen(other.email) + 1];
        strcpy(this->email, other.email);
    }
}
Person::~Person()
{
    delete[] this->email;
    delete[] this->name;
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
    if (!email)
        return;
    if (!IsItEmail(email))
    {
        this->email = nullptr;
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
    if (years > 90 || years <= 0)
        return;
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
const char *Person::getName() const
{
    return this->name;
}
int Person::getYears() const
{
    return this->years;
}
const char *Person::getEmail() const
{
    if (this->email)
    {
        return this->email;
    }
}
int Person::getId() const
{
    return this->id;
}
void Person::profile_info(const char *name) const
{
    if (strcmp(this->name, name) == 0)
    {
        std::cout << "PERSON NAME: " << this->name << ", ";
        if (this->years <= 0)
        {
            std::cout << "YEARS: UNKNOWN, ";
        }
        else
        {
            std::cout << "YEARS: " << this->years << ", ";
        }

        if (this->email == nullptr || this->email == "\0" || this->email == "" || this->email == " " || this->email == "0null")
        {
            std::cout << "EMAIL: UNKNOWN, ";
        }
        else
        {
            std::cout << "EMAIL: " << this->getEmail() << ", ";
        }
        std::cout << "ID: " << this->id << "\n";
    }
}
void Person::print(std::ostream &out)
{
    std::ifstream in("USERS.txt", std::ios::in);

    if (!out)
        return;

    out << "\n";
    in.close();
    out << this->name << " ";
    if (this->years <= 0)
    {
        out << 0
            << " ";
    }
    else
    {
        out << this->years << " ";
    }

    if (this->email == nullptr || this->email == "\0" || this->email == "" || this->email == " ")
    {
        out << "0null"
            << " ";
    }
    else
    {
        out << this->email << " ";
    }
    out << this->id;
}
bool Person::operator==(const Person &other)
{
    return this->id == other.id && strcmp(this->name, other.name) == 0 && this->years == other.years;
}

bool Person::read(std::istream &in)
{

    if (!in)
    {
        return false;
    }
    char name[50];
    in >> name;
    name[strlen(name)] = '\0';
    int years, id;
    in >> years;

    char email[49];
    in >> email;
    email[strlen(email)] = '\0';
    in >> id;
    if (in)
    {

        this->setName(name);
        this->setYears(years);
        this->setEmail(email);
        this->setId(id);
        return true;
    }
    else
    {
        return true;
        if (in.eof())
        {
            std::cout << "The EOF has been reached!" << std::endl;
        }
        else
        {
            in.clear();
            in.ignore(1024, '\n');
        }

        return true;
        ;
    }
}