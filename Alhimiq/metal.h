#include <string>
#include <vector>
#include "earth.h"
#include "fire.h"
class Metal : public Earth, public Fire
{
protected:
    std::string name = "Metal";
    std::vector<std::string> reactWith;

public:
    Metal();
    ~Metal();
     void print()const ;
};


