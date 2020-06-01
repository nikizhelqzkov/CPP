#include "Organization.h"

void Organization::copy(const Organization &other)
{
    for (Institution *list : other.institutions_list)
    {
        this->institutions_list.push_back(list->clone());
    }
}
void Organization::clear()
{
    for (Institution *&list : this->institutions_list)
    {
        delete list;
        list = nullptr;
    }
}
int Organization::count2()
{
    int count = 0;
    for (Institution *l : institutions_list)
    {
        if (l->type() == "Group")
        {
            count++;
        }
        if (l->type() == "Organization")
        {
            count += Organization::count();
        }
    }
    return count;
}
int Organization::count() const
{
    int count = 0;
    for (Institution *l : institutions_list)
    {
        count += l->count();
    }
    return count;
}

Organization::Organization(std::string name, std::vector<Institution *> list, std::string address) : Institution(name),
                                                                                                     institutions_list(list), organization_address(address)
{
    setId(this->count());
    std::cout << "ID -> " << this->getId() << std::endl;
}
//setId();

Organization::~Organization()
{
    this->clear();
}
Organization::Organization(const Organization &other)
{
    this->copy(other);
}
Organization &Organization::operator=(const Organization &other)
{
    if (this != &other)
    {
        this->copy(other);
        this->clear();
    }

    return *this;
}
Institution *Organization::operator[](size_t index)
{
    return this->institutions_list[index];
}
const Institution *Organization::operator[](size_t index) const
{
    return this->institutions_list[index];
}
int Organization::getCountOfList() const
{
    return this->institutions_list.size();
}
std::vector<Institution *> Organization::getList() const
{
    return this->institutions_list;
}
bool Organization::has_member(Person person) const
{
    for (Institution *list : this->institutions_list)
    {
        if (list->has_member(person))
        {
            return true;
        }
    }
    return false;
}
const Payer *Organization::payer(const Payer *p)
{
    if (getCountOfList() == 0)
    {
        this->group_payer = p;
        return p;
    }
    int minCount = 0;
    int count = 0;
    for (int i = 0; i < this->institutions_list.size(); ++i)
    {
        count = 0;
        for (int j = 0; j < institutions_list.size(); ++j)
        {
            if (this->institutions_list[i]->getPayer()->getName() == this->institutions_list[j]->getPayer()->getName() && this->institutions_list[i]->getPayer()->getId() == this->institutions_list[j]->getPayer()->getId())
            {
                count++;
            }
        }
        if (minCount < count)
        {
            minCount = count;
            this->group_payer = this->institutions_list[i]->getPayer();
        }
    }

    return this->group_payer;
}
bool Organization::valid() const
{
    bool valid = false;
    for (Institution *list : this->institutions_list)
    {
        valid = false;
        // if (list->type() == "Organization")
        // {
        //     valid = list->valid();
        //     if (valid)
        //     {
        //         return true;
        //     }
        // }
        // else if (list->type() == "Group")
        // {
        //     valid = list->valid();
        //     if (valid)
        //     {
        //         return true;
        //     }
        // }
        valid = list->valid();
        if (valid)
        {
            return true;
        }
    }
    return false;
}
Institution *Organization::clone() const
{
    return new Organization();
}
const Payer *Organization::getPayer() const
{
    return this->group_payer;
}
std::string Organization::type() const
{
    return this->typeName;
}
bool Organization::compatible(const Organization &other) const
{
    return this->group_payer == other.group_payer;
}
