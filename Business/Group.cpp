#include "Group.h"

Group::Group(std::string name, bool hasAPayer) : Institution(name)
{
    this->has = hasAPayer;
}
Group::~Group()
{
    delete group_payer;
}
const Payer *Group::payer(const Payer *p)
{
    if (has)
    {
        this->group_payer = p;
    }
    return this->group_payer;
}
void Group::addGroupId()
{
    if (has)
    {
        group_id = this->group_payer->getId();
    }
}

bool Group::has_member(Person person) const
{
    return group_payer->payer_member_rule(this->group_id, person.getId());
}

bool Group::valid() const
{
    return has;
}
Institution *Group::clone() const
{
    return new Group();
}
int Group::getId() const
{
    return this->group_id;
}
const Payer *Group::getPayer() const
{
    return this->group_payer;
}
std::string Group::type() const
{
    return this->typeName;
}
int Group::count()const{
    return 1;
}
