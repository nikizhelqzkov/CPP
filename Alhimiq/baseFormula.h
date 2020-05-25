#pragma once
#include "uravnenie.h"
class BaseFormula
{


protected:
    virtual bool isItValid()  = 0;
    BaseFormula() = default;
   
   // virtual BaseFormula &operator=(const BaseFormula &other);

public:
    virtual ~BaseFormula();
    virtual void print()const = 0;
};
