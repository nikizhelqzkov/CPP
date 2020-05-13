#include <string>
#include <vector>
#include "water.h"
#include "fire.h"
class Stone : public Fire, public Water
{
protected:
    std::string name = "Stone";
    std::vector<std::string> reactWith;

public:
    Stone();
    ~Stone();
    void print()const ;
};
