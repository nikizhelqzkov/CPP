#include <string>
#include <vector>
#include<iostream>
class Air
{
protected:
    std::string name = "Air";
    std::vector<std::string> reactWith{"Air","Water","Fire","Earth"};

public:
    Air();
    ~Air();
    void print()const;
};


