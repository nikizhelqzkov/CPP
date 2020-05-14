#pragma once
#include <string>
#include <vector>
#include "air.h"
class Spirit : public Air
{
protected:
    std::string name = "Spirit";
    std::vector<std::string> reactWith;

public:
    Spirit();
    ~Spirit();
    virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
};
