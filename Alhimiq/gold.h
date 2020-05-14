#pragma once
#include <string>
#include <vector>
#include "metal.h"
class Gold : public Metal
{
protected:
    std::string name = "Gold";
    std::vector<std::string> reactWith;

public:
    Gold();
    ~Gold();
    virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
};
