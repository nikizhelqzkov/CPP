#pragma once
#include "elements.h"
#include <string>
#include <vector>
#include <iostream>
class Water:public Elements
{
protected:
    std::string name = "Water";
    std::vector<std::string> reactWith{"Air", "Fire"};

public:
    Water() = default;
    ~Water();
  virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
};
