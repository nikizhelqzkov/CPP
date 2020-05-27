#pragma once
#include "elements.h"
#include <string>
#include <vector>
#include "metal.h"
class Gold : virtual public Elements, public Metal
{
protected:
    std::string name = "Gold";
    std::vector<std::string> reactWith;
    std::vector<std::string> father{"Metal"};

public:
    Gold();
    ~Gold();
    virtual std::vector<std::string> getReactings() const override;
    virtual std::string getName() const override;
    virtual void print() const override;
    virtual Elements *clone() const override;
    virtual std::vector<std::string> getFathers() const override;
    static Gold *read(std::istream &);

};
