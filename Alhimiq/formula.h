#pragma once
#include "baseFormula.h"
class Formula : virtual public BaseFormula
{
private:
    Elements *elem;
    Uravnenie ur;
    bool valid = false;
    std::vector<Elements *>el_2{nullptr};

public:
    Formula() = default;
    Formula(const Uravnenie &, Elements *);
    Formula(const Formula &);
    virtual ~Formula() override;
    virtual void print() const override;
    virtual bool isItValid() const override;
    virtual BaseFormula *clone() const override;
    virtual Uravnenie getUr() const override;
    virtual Elements *getEl() const override;
    virtual std::vector<Elements *> getEl_2() const override;
};
