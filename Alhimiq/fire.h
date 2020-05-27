#pragma once
#include "elements.h"
#include <string>
#include <vector>
#include <iostream>
class Fire : virtual public Elements
{
protected:
    std::string name = "Fire";
    std::vector<std::string> reactWith{"Earth", "Water", "Fire"};
    std::vector<std::string> father{"0"};

public:
    Fire() = default;
    ~Fire();
    virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
    virtual std::vector<std::string> getFathers() const override;
    static Fire *read(std::istream &);
};
