#ifndef ARR_PERSON
#define ARR_PERSON
#include "Person.h"

class PersonArr
{
private:
    Person *arr;
    size_t size;

public:
    PersonArr(const Person * ,size_t);
    PersonArr(const PersonArr&);
    ~PersonArr();
    PersonArr& operator=(const PersonArr&);
    void SetArr(const Person*,size_t);
    Person* getArr()const;
    size_t getSize()const;
    void printArr()const;
    Person& operator[](int i);
    Person operator[](int i)const;
    PersonArr& operator+=(const Person&);
};






#include "PersonArr.hpp"

#endif