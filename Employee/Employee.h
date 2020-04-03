#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <fstream>
class Employee
{
private:
    char *name;
    double worktime;
    double hourSalary;

public:
    // Employee();
    Employee(const char *name = "", double worktime = 0, double hourSalary = 0);
    Employee(const Employee &other);
    ~Employee();
    Employee &operator=(const Employee &other);
    const char *getName() const;
    double getWorktime() const;
    double getHourSalary() const;
    // void setEmployee(const char *, double, double);
    void setName(const char *);
    void setWorktime(double);
    void setHourSalary(double);

    void print(std::ostream & = std::cout);
    bool read(std::istream & = std::cin);
    bool storeInBin(std::ostream &);

    bool loadFromBin(std::istream &);
};

#endif
