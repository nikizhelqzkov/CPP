#pragma once
#include "elements.h"
#include <string>
#include <vector>
#include "earth.h"
#include "fire.h"
class Metal : virtual public Elements, public Earth, public Fire
{
protected:
    std::string name = "Metal";
    std::vector<std::string> reactWith;
    std::vector<std::string> father{"Earth", "Fire"};

public:
    Metal();
    ~Metal();
    virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
    virtual std::vector<std::string> getFathers() const override;
    static Metal *read(std::istream &);
};
