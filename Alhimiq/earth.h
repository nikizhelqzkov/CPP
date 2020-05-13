#include <string>
#include <vector>
#include<iostream>
class Earth
{
protected:
    std::string name = "Earth";
    std::vector<std::string> reactWith{"Fire","Air","Water"};

public:
    Earth();
    ~Earth();
    void print()const ;
};


