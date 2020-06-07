#include "Payer.h"

Payer::Payer()
{
    this->name = "";
    this->id = 0;
}
Payer::Payer(std::string _name, int _id, rule f) : name(_name), id(_id), payer_rule(f)
{
    this->fRule = f;
}
Payer::Payer(const Payer &other)
{
    this->name = other.name;
    this->id = other.id;
    this->payer_rule = other.payer_rule;
}
Payer::~Payer() {}
Payer &Payer::operator=(const Payer &other)
{
    if (this != &other)
    {
        setName(other.name);
        setId(other.id);
    }
    return *this;
}
bool Payer::payer_member_rule(rule f, int group_id, int person_id) const
{
    return f(group_id, person_id);
}
std::string Payer::getName() const
{
    return this->name;
}
int Payer::getId() const
{
    return this->id;
}
void Payer::setName(std::string name)
{
    this->name = name;
}
void Payer::setId(int id)
{
    this->id = id;
}
std::function<int(int, int)> Payer::getRule() const
{
    return this->fRule;
}