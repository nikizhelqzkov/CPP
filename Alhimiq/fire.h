#include <string>
#include <vector>
#include <iostream>
class Fire
{
protected:
    std::string name = "Fire";
    std::vector<std::string> reactWith{"Earth", "Water", "Fire"};

public:
    Fire() = default;
    ~Fire();
    std::vector<std::string> getReactings() const;
    std::string getName() const;
    void print() const;
};
