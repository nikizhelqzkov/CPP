#pragma once
#include "uravnenie.h"
class BaseFormula
{

protected:
    BaseFormula() = default;

    // virtual BaseFormula &operator=(const BaseFormula &other);

public:
    virtual ~BaseFormula();
    virtual void print() const = 0;
    virtual BaseFormula *clone() const = 0;
    virtual bool isItValid() const = 0;
    virtual Uravnenie getUr() const = 0;
    virtual Elements* getEl()const = 0;
    virtual std::vector<Elements *>getEl_2()const = 0;
};
