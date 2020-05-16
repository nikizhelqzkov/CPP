#pragma once
#include "elements.h"
#include <string>
#include <vector>
#include <iostream>
class Fire:virtual public Elements
{
protected:
    std::string name = "Fire";
    std::vector<std::string> reactWith{"Earth", "Water", "Fire"};

public:
    Fire() = default;
    ~Fire();
    virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
};
