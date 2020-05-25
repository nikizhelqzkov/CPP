#pragma once
#pragma once
#include "elements.h"
#include <string>
#include <vector>
#include "water.h"
#include "air.h"
#include "fire.h"
#include "earth.h"
class PS : virtual public Elements, public Earth, public Fire, public Water, public Air
{
protected:
    std::string name = "Philosopher's Stone";
    std::vector<std::string> reactWith;
    std::vector<std::string> father{"0"};

public:
    PS();
    ~PS();
    virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
    virtual std::vector<std::string> getFathers() const override;
};
