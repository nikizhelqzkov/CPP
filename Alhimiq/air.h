#pragma once
#include "elements.h"
#include <string>
#include <vector>
#include <iostream>
class Air : virtual public Elements
{
protected:
    std::string name = "Air";
    std::vector<std::string> reactWith{"Air", "Water", "Fire", "Earth"};
    std::vector<std::string> father{"0"};
 
public:
   

    Air() = default;
    ~Air();
    virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
    virtual std::vector<std::string> getFathers() const override;
    static Air *read(std::istream &);
};
