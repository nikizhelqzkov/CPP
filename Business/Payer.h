#ifndef PAYER_INCLUDED
#define PAYER_INCLUDED
#include <string>
#include <functional>

class Payer
{
private:
    std::string name;
    int id;
    bool payer_rule = true;

public:
    using rule = std::function < bool(int, int)>;
    Payer();
    Payer(std::string, int, rule);
    Payer(const Payer &);
    ~Payer();
    Payer &operator=(const Payer &);
    bool payer_member_rule(rule, int, int) const;
    std::string getName() const;
    int getId() const;
    void setName(std::string);
    void setId(int);
};

#endif