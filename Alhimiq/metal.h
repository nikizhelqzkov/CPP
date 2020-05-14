#pragma once

#include <string>
#include <vector>
#include "earth.h"
#include "fire.h"
class Metal :  public Earth, public Fire
{
protected:
    std::string name = "Metal";
    std::vector<std::string> reactWith;

public:
    Metal();
    ~Metal();
    virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
};
