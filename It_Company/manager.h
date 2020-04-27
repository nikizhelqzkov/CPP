#pragma once
#include "employ.h"
class Manager : virtual public Employ
{
private:
    size_t countManage;

protected:
    virtual void printOwn() const override;

public:
    Manager(const char *, size_t, size_t);
    size_t getCountManage() const;
    Manager(const Manager &);
    Manager &operator=(const Manager &);
    Employ **addEmploy(Employ *arr[], size_t size);
    Employ** removeEmploy(Employ* arr[],size_t size);
    
};
