#pragma once
#include <string>
#include <vector>
class Elements
{

public:
    // Elements(){};
    virtual ~Elements(){};
    virtual void print() const = 0;
    virtual Elements *clone() const = 0;
    virtual std::vector<std::string> getReactings() const = 0;
    virtual std::string getName() const = 0;
    virtual std::vector<std::string> getFathers() const = 0;
  
};
