#include <string>
#include <vector>
#include<iostream>
class Water
{
protected:
    std::string name = "Water";
    std::vector<std::string> reactWith{"Air","Fire"};

public:
    Water();
    ~Water();
    void print()const ;
};
