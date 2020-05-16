#pragma once
#include "elements.h"
#include <string>
#include <vector>
#include "water.h"
#include "fire.h"
class Stone :virtual public Elements, public Fire, public Water
{
protected:
    std::string name = "Stone";
    std::vector<std::string> reactWith;

public:
    Stone();
    ~Stone();
     virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
};
