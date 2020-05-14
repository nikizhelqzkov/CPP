#include <string>
#include <vector>
#include <iostream>
class Earth
{
protected:
    std::string name = "Earth";
    std::vector<std::string> reactWith{"Fire", "Air", "Water"};

public:
    Earth() = default;
    ~Earth();
    std::vector<std::string> getReactings() const;
    std::string getName() const;
    void print() const;
};
