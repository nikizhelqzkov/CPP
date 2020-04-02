#include "Employee.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <iomanip>
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
void Employee::setEmployee(const char *name, double worktime, double hourSalary)
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
void Employee::setName(const char *name)
{
    delete[] this->name;
    assert(name && strlen(name) > 0 && strlen(name) < 50);
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
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
bool Employee::print(std::ostream &out) const
{
    if (!out)
        return false;
    out << std::setiosflags(std::ios::fixed) << std::setprecision(2);
    out << this->name << '\t' << this->worktime << '\t' << this->hourSalary << std::endl;
    return out.good();
}
bool Employee::read(std::istream &in)
{
    if (!in)
        return false;
    char buffer[255];
    double workTime = 0;
    double hourSalary = 3.5;
    in.getline(buffer, 255, '\t');
    in >> worktime >> hourSalary;
    if (in)
    {
        this->setName(buffer);
        this->setWorktime(worktime);
        this->setHourSalary(hourSalary);
        return true;
    }
    else if (in.eof())
    {
        std::cout << "END OF FILE\n";
        return false;
    }
    else if (in.fail())
    {
        in.clear();
        in.ignore(1024, '\n');
    }

    return false;
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
    int size = 0;
    in.read(reinterpret_cast<char *>(&size), sizeof(int));
    if (in && in.gcount() == sizeof(size))
    {
        char *buffer = new char[size + 1];
        in.read(reinterpret_cast<char *>(buffer), sizeof(char) * size);
        buffer[size] = '\0';
        if (in)
        {
            strcpy(this->name, buffer);
            double worktime = 0;
            in.read((char *)(&worktime), sizeof(double));

            //this->worktime = worktime;
            double hourSalary = 3.5;
            in.read(reinterpret_cast<char *>(&hourSalary), sizeof(double));

            // this->hourSalary = hourSalary;

            if (in)
            {
                delete[] this->name;
                this->name = buffer;
                this->setWorktime(worktime);
                this->setHourSalary(hourSalary);
                return true;
            }
        }
        delete[] buffer;
    }
    return false;
}