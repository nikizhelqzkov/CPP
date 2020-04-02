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
    void setEmployee(const char*,double,double);
    void setWorktime(double);
    void setHourSalary(double);
    void setName(const char*);
    bool print(std::ostream& out=std::cout)const;
    bool read(std::istream&);
    bool storeInBin(std::ostream& out)const;
    bool loadFromBin(std::istream& in);
};





#endif
