#pragma once
#include "baseFormula.h"
class Formula2 : virtual public BaseFormula
{
private:
    Uravnenie data;
    std::vector<Elements *> el;
    Air a;
    Fire f;
    Metal m;
    Earth e;
    Water w;
    std::vector<Elements *> el2 = {&e, &f, &w, &a, &m};
    Elements *elem{nullptr};

public:
    Formula2(const Uravnenie &);
    Formula2(const Formula2 &);
    virtual ~Formula2() override;
    virtual void print() const override;
    void Print() const;
    virtual bool isItValid() const override;
    virtual BaseFormula *clone() const override;
    virtual Uravnenie getUr() const override;
    virtual Elements *getEl() const override;
    virtual std::vector<Elements *> getEl_2() const override;
};
