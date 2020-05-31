#ifndef PERSON_INCLUDED
#define PERSON_INCLUDED
#include <string>

class Person
{
private:
    std::string person_name;
    int insurance_id;

public:
    Person();
    Person(std::string, int);
    ~Person();
    std::string getName()const;
    int getId()const;
    void setName(std::string);
    void setId(int);
};

#endif