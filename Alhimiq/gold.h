#include <string>
#include <vector>
#include "metal.h"
class Gold : public Metal
{
protected:
    std::string name = "Gold";
    std::vector<std::string> reactWith;

public:
    Gold();
    ~Gold();
    std::vector<std::string> getReactings() const;
    std::string getName() const;
    void print() const;
};
