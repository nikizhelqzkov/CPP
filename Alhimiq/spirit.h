#include <string>
#include <vector>
#include "air.h"
class Spirit : public Air
{
protected:
    std::string name = "Spirit";
    std::vector<std::string> reactWith;

public:
    Spirit();
    ~Spirit();
    std::vector<std::string> getReactings() const;
    std::string getName() const;
    void print() const;
};
