#include "Payer.h"

Payer::Payer()
{
    this->name = "";
    this->id = 0;
}
Payer::Payer(std::string _name, int _id) : name(_name), id(_id) {}
Payer::Payer(const Payer &other) : Payer(other.name, other.id) {}
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
bool Payer::payer_member_rule(int groupId, int PersonId) const
{
    return groupId == PersonId;
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