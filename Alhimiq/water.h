#include <string>
#include <vector>
#include <iostream>
class Water
{
protected:
    std::string name = "Water";
    std::vector<std::string> reactWith{"Air", "Fire"};

public:
    Water() = default;
    ~Water();
    std::vector<std::string> getReactings() const;
    std::string getName() const;
    void print() const;
};
