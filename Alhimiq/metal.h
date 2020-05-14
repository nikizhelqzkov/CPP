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
    std::vector<std::string> getReactings() const;
    std::string getName() const;
    void print() const;
};
