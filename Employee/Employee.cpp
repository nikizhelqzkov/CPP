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
    std::cout<<"hello";
}
