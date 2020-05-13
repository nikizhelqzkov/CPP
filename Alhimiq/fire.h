#include <string>
#include <vector>
#include <iostream>
class Fire
{
protected:
    std::string name = "Fire";
    std::vector<std::string> reactWith{"Earth", "Water", "Fire"};

public:
    Fire();
    ~Fire();
    std::vector<std::string> getEl() const;
     void print() const;
};
