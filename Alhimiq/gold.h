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
    void print()const ;
};
