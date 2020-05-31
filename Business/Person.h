#ifndef PERSON_INCLUDED
#define PERSON_INCLUDED
#include <string>

class Person
{
private:
    std::string person_name;
    int insurance_id;
    bool hasPayer;

public:
    Person();
    Person(std::string,bool);

    ~Person();
    std::string getName()const;
    int getId()const;
    bool getHasPayer()const;
    void setName(std::string);
    void setId(int);
    
};

#endif