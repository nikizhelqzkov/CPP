#pragma once
#include "elements.h"
#include <string>
#include <vector>
#include <iostream>
class Earth:virtual public Elements
{
protected:
    std::string name = "Earth";
    std::vector<std::string> reactWith{"Fire", "Air", "Water"};

public:
    Earth() = default;
    ~Earth();
    virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
};
