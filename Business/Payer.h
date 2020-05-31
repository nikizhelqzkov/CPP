#ifndef PAYER_INCLUDED
#define PAYER_INCLUDED
#include <string>

class Payer
{
private:
    std::string name;
    int id;
    
public:
    Payer();
    Payer(std::string,int);
    Payer(const Payer&);
    ~Payer();
    Payer& operator=(const Payer&);
    bool payer_member_rule(int,int)const;
    std::string getName()const;
    int getId()const;
    void setName(std::string);
    void setId(int);
};





#endif