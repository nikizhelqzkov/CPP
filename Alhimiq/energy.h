#pragma once
#include "elements.h"
#include <string>
#include <vector>
#include "water.h"
#include "air.h"
class Energy : virtual public Elements, public Water, public Air
{
protected:
    std::string name = "Energy";
    std::vector<std::string> reactWith;

public:
    Energy();
    ~Energy();
    virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
};
