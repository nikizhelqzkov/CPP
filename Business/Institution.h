#ifndef INSTITUTION_INCLUDED
#define INSTITUTION_INCLUDED
#include "Payer.h"
#include "Person.h"
class Institution
{
private:
    std::string name;
    int id;

public:
    Institution() = default;
    Institution(std::string, int);
    virtual ~Institution();
    virtual bool has_memebr(Person) const = 0;
    virtual Payer &payer(const Payer &) const = 0;
    virtual bool valid() const = 0;
    virtual Institution *clone() const = 0;
};

#endif