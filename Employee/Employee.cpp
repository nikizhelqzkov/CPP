#include "Employee.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <cstring>
Employee::Employee()
{
    this->name = nullptr;
    this->worktime = 0;
    this->hourSalary = 0;
}
Employee::Employee(const char *name, double worktime, double hourSalary)
{
    assert(name && strlen(name) > 0 && strlen(name) < 50);
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    assert(worktime > 0);
    this->worktime = worktime;
    assert(hourSalary > 3.5);
    this->hourSalary = hourSalary;
}
Employee::Employee(const Employee &other)
{
    strcpy(this->name, other.name);
    this->worktime = other.worktime;
    this->hourSalary = other.hourSalary;
}
Employee::~Employee()
{
    delete[] this->name;
}
char *Employee::getName() const
{
    return this->name;
}
double Employee::getWorktime() const
{
    return this->worktime;
}
double Employee::getHourSalary() const
{
    return this->hourSalary;
}
void Employee::setEmployee(char *name, double worktime, double hourSalary)
{
    delete[] this->name;
    assert(name && strlen(name) > 0 && strlen(name) < 50);
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    assert(worktime > 0);
    this->worktime = worktime;
    assert(hourSalary > 3.5);
    this->hourSalary = hourSalary;
}
void Employee::setWorktime(double worktime)
{
    assert(worktime > 0);
    this->worktime = worktime;
}
void Employee::setHourSalary(double worktime)
{
    assert(hourSalary > 3.5);
    this->hourSalary = hourSalary;
}
void Employee::print()
{
    std::cout << this->name << '\t' << this->worktime << '\t' << this->hourSalary << std::endl;
    std::cout << "hello";
}
bool Employee::storeInBin(std::ostream &out) const
{
    if (!out)
    {
        return false;
    }
    size_t size = strlen(this->name);
    out.write(reinterpret_cast<const char *>(&size), sizeof(size_t));
    out.write(reinterpret_cast<const char *>(&this->name), sizeof(this->name));
    out.write(reinterpret_cast<const char *>(&this->worktime), sizeof(this->worktime));
    out.write(reinterpret_cast<const char *>(&this->hourSalary), sizeof(this->hourSalary));
    return out.good();
}
bool Employee::loadFromBin(std::istream &in)
{
    if (!in)
    {
        return false;
    }
    size_t size;
    in.read(reinterpret_cast<const char *>(&size), sizeof(size));
    if (in && in.gcount() == sizeof(size))
    {
        char *buffer = new char[size + 1];
        in.read(reinterpret_cast<const char *>(buffer), sizeof(char) * size);
        if (in && in.gcount() == sizeof(char) * size)
        {
            strcpy(this->name, buffer);
            double worktime;
            in.read(reinterpret_cast<const char *>(&worktime), sizeof(worktime));
            if (in && in.gcount() == sizeof(worktime))
            {
                this->worktime = worktime;
                double hourSalary;
                in.read(reinterpret_cast<const char *>(&hourSalary), sizeof(hourSalary));
                if (in && in.gcount() == sizeof(hourSalary))
                {
                    this->hourSalary = hourSalary;
                    return true;
                }
            }
        }
        else
        {
            delete[] buffer;
        }
    }
    return false;
}