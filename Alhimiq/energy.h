#include <string>
#include <vector>
#include "water.h"
#include "air.h"
class Energy : public Water, public Air
{
protected:
    std::string name = "Energy";
    std::vector<std::string> reactWith;

public:
    Energy();
    ~Energy();
    void print()const ;
};


