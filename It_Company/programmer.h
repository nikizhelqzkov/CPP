#pragma once
#include "employ.h"
class Programmer : virtual public Employ
{
private:
    bool knowCPP{false};
    bool knowCS{false};

protected:
    virtual void printOwn() const override;

public:
    Programmer(const char *, size_t, bool, bool);
    Programmer(const Programmer &);
    Programmer &operator=(const Programmer &);
    bool getKnowCPP() const;
    bool getKnowCS() const;
    Employ **addEmploy(Employ *arr[], size_t size);
    Employ **removeEmploy(Employ *arr[], size_t size);
};
