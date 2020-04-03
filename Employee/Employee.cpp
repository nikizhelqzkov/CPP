#include "Employee.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <iomanip>

Employee::Employee(const char* name, double worktime, double hourSalary)
    : name(nullptr), worktime(0), hourSalary(0)
{
    this->setName(name);
    this->setWorktime(worktime);
    this->setHourSalary(hourSalary);
}

Employee::Employee(const Employee& other)
    :Employee(other.name, other.worktime, other.hourSalary)
{}

Employee& Employee::operator = (const Employee& other)
{
    if(this != &other)
    {
        this->setName(other.name);
        this->setWorktime(other.worktime);
        this->setHourSalary(other.hourSalary);
    }

    return *this;
}

Employee::~Employee()
{
    delete [] this->name;
    this->name = nullptr;
}

const char* Employee::getName() const
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

void Employee::setName(const char* name)
{
    if(!name) name = "";

    delete [] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Employee::setWorktime(double worktime)
{
    assert(worktime >= 0 && worktime <= 60);
    this->worktime = worktime;
}

void Employee::setHourSalary(double hourSalary)
{
    assert(hourSalary >= 0);
    this->hourSalary = hourSalary;
}

void Employee::print(std::ostream& out)
{
    if(!out) return;

    out << this->name << '\t' << this->worktime << '\t' << this->hourSalary << std::endl;
}

bool Employee::read(std::istream& in)
{
    if(!in) return false;

    char name[255];
    in.getline(name, 255, '\t');

    double worktime, hourSalary;
    in >> worktime >> hourSalary;

    if(in)
    {
        this->setName(name);
        this->setWorktime(worktime);
        this->setHourSalary(hourSalary);

        return true;
    }
    else
    {
        if(in.eof())
        {
            std::cout << "The EOF has been reached!" << std::endl;
        }
        else
        {
            in.clear();
            in.ignore(1024, '\n');
        }

        return false;
    }
}

bool Employee::storeInBin(std::ostream& out)
{
    if(!out) return false;

    /// ��������� ����� ��������� �� ����, �� �� ����� ����� ����� ������� �� ��������
    int length = strlen(this->name);
    out.write(reinterpret_cast<const char*>(&length), sizeof(int));
    out.write(reinterpret_cast<const char*>(this->name), length*sizeof(char));

    out.write(reinterpret_cast<const char*>(&this->worktime), sizeof(double));
    out.write(reinterpret_cast<const char*>(&this->hourSalary), sizeof(double));

    return out.good();
}

bool Employee::loadFromBin(std::istream& in)
{
    if(!in)
    {
        std::cout << "The input binary file cannot be used for reading!" << std::endl;
        return false;
    }

    int length = 0;
    in.read(reinterpret_cast<char*>(&length), sizeof(int));

    char* buffer = new char[length + 1];
    in.read(reinterpret_cast<char*>(buffer), length*sizeof(char));
    buffer[length] = '\0';

    double worktime = 0, hourSalary = 0;
    in.read(reinterpret_cast<char*>(&worktime), sizeof(double));
    in.read(reinterpret_cast<char*>(&hourSalary), sizeof(double));

    if(in.fail())
    {
        delete [] buffer;
        return false;
    }
    else
    {
        delete [] this->name;
        this->name = buffer;

        this->setWorktime(worktime);
        this->setHourSalary(hourSalary);

        return true;
    }
}

// Employee::Employee(const char* name, double worktime, double hourSalary)
//     : name(nullptr), worktime(0), hourSalary(3.50)
// {
//     this->setName(name);
//     this->setWorktime(worktime);
//     this->setHourSalary(hourSalary);
// }

// Employee::Employee(const Employee& other)
//     :Employee(other.name, other.worktime, other.hourSalary)
// {}

// Employee& Employee::operator = (const Employee& other)
// {
//     if(this != &other)
//     {
//         this->setName(other.name);
//         this->setWorktime(other.worktime);
//         this->setHourSalary(other.hourSalary);
//     }

//     return *this;
// }


// Employee::~Employee()
// {
//     delete[] this->name;
//     this->name = nullptr;
// }
// char *Employee::getName() const
// {
//     return this->name;
// }
// double Employee::getWorktime() const
// {
//     return this->worktime;
// }
// double Employee::getHourSalary() const
// {
//     return this->hourSalary;
// }
// void Employee::setEmployee(const char *name, double worktime, double hourSalary)
// {
//     delete[] this->name;
//     assert(name && strlen(name) > 0 && strlen(name) < 50);
//     this->name = new char[strlen(name) + 1];
//     strcpy(this->name, name);
//     assert(worktime > 0);
//     this->worktime = worktime;
//     assert(hourSalary > 3.5);
//     this->hourSalary = hourSalary;
// }
// void Employee::setName(const char *name)
// {
//       if(!name) name = "";

//     delete [] this->name;
//     this->name = new char[strlen(name) + 1];
//     strcpy(this->name, name);
// }
// void Employee::setWorktime(double worktime)
// {
//     assert(worktime >= 0);
//     this->worktime = worktime;
// }
// void Employee::setHourSalary(double hourSalary)
// {
//     assert(hourSalary >= 0);
//     this->hourSalary = hourSalary;
// }
// void Employee::print(std::ostream &out) const
// {
//     if (!out)
//         return;
//     // out << std::setiosflags(std::ios::fixed) << std::setprecision(3);
//     out << this->name << '\t' << this->worktime << '\t' << this->hourSalary << std::endl;
// }
// bool Employee::read(std::istream &in)
// {
//     if (!in)
//         return false;
//     char buffer[255];
//     double workTime = 0;
//     double hourSalary = 3.5;
//     in.getline(buffer, 255, '\t');
//     in >> worktime >> hourSalary;
//     if (in)
//     {
//         this->setName(buffer);
//         this->setWorktime(worktime);
//         this->setHourSalary(hourSalary);
//         return true;
//     }
//     else
//     {

//         if (in.eof())
//         {
//             std::cout << "END OF FILE\n";
//             // return false;
//         }
//         else
//         {
//             in.clear();
//             in.ignore(1024, '\n');
//         }
//         return false;
//     }
// }
// bool Employee::storeInBin(std::ostream &out) const
// {
//     if (!out)
//     {
//         return false;
//     }
//     int size = strlen(this->name);
//     out.write(reinterpret_cast<const char *>(&size), sizeof(int));
//     out.write(reinterpret_cast<const char *>(this->name), size * sizeof(char));
//     out.write(reinterpret_cast<const char *>(&this->worktime), sizeof(double));
//     out.write(reinterpret_cast<const char *>(&this->hourSalary), sizeof(double));
//     return out.good();
// }
// bool Employee::loadFromBin(std::istream &in)
// {
//     if (!in)
//     {
//         return false;
//     }
//     int size = 0;
//     in.read(reinterpret_cast<char *>(&size), sizeof(int));

//     char *buffer = new char[size + 1];
//     in.read(reinterpret_cast<char *>(buffer), sizeof(char) * size);
//     buffer[size] = '\0';

//     strcpy(this->name, buffer);
//     double worktime = 0;
//     in.read((char *)(&worktime), sizeof(double));

//     //this->worktime = worktime;
//     double hourSalary = 3.5;
//     in.read(reinterpret_cast<char *>(&hourSalary), sizeof(double));

//     //this->hourSalary = hourSalary;

//     if (in.fail())
//     {
//         delete[] buffer;

//         return false;
//     }
//     else
//     {
//         delete[] this->name;
//         this->name = buffer;
//         this->setWorktime(worktime);
//         this->setHourSalary(hourSalary);
//         return true;
//     }
// }