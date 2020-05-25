#pragma once
#include "elements.h"
#include <string>
#include <vector>
#include <iostream>
class Earth : virtual public Elements
{
protected:
    std::string name = "Earth";
    std::vector<std::string> reactWith{"Fire", "Air", "Water"};
    std::vector<std::string> father{"0"};

public:
    Earth() = default;
    ~Earth();
    virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
    virtual std::vector<std::string> getFathers() const override;
};
