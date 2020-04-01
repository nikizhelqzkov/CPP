#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <fstream>
class Employee
{
private:
   char* name;
   double worktime;
   double hourSalary;
public:
    Employee();
    Employee(const char*,double,double);
    Employee(const Employee&);
    ~Employee();
    char* getName()const;
    double getWorktime()const;
    double getHourSalary()const;
    void setEmployee(char*,double,double);
    void setWorktime(double);
    void setHourSalary(double);
    void print(std::ostream&)const;
    bool storeInBin(std::ostream& out)const;
    bool loadFromBin(std::istream& in);
};





#endif
