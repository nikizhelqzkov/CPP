#pragma once
#include "baseFormula.h"
class Formula : virtual public BaseFormula
{
private:
    Elements *elem;
    Uravnenie ur;
    bool valid = false;

public:
    Formula() = default;
    Formula(const Uravnenie &, Elements *);
    Formula(const Formula &);
    // Formula& operator=(const Formula&);
    virtual ~Formula() override;
    virtual void print() const override;
    virtual bool isItValid()  override;
};
