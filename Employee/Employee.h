#ifndef EMPLOYEE_H
#define EMPLOYEE_H

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
    void print();

};




#endif
