#pragma once
#include "programmer.h"
#include "manager.h"

class EmpArr
{
private:
    Employ** arr;
    size_t size;
public:
    EmpArr(const Employ**,size_t);
    EmpArr(const EmpArr&);
    ~EmpArr();
    EmpArr& operator=(const EmpArr&);
    void setEmpArr(const Employ**,size_t);
};


