#ifndef ORGANIZATION_INCLUDED
#define ORGANIZATION_INCLUDED
#include "Group.h"
#include <vector>
class Organization : public Institution
{
private:
    std::vector<Institution *> institutions_list;
    std::string organization_address;
    const Payer *group_payer = nullptr;
    std::string typeName = "Organization";

    void copy(const Organization &);
    void clear();
    int count2();

public:
    Organization() = default;
    Organization(std::string, std::vector<Institution *>, std::string);
    ~Organization();
    Organization(const Organization &);
    Organization &operator=(const Organization &);
    Institution *operator[](size_t index);
    const Institution *operator[](size_t index) const;
    int getCountOfList() const;
    std::vector<Institution *> getList() const;
    virtual bool has_member(Person) const override;
    virtual const Payer *payer(const Payer *) override;
    virtual bool valid() const override;
    virtual Institution *clone() const override;
    virtual const Payer *getPayer() const override;
    virtual std::string type() const override;
    bool compatible(const Organization &) const;
    virtual int count() const override;
};

#endif