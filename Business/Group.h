#ifndef GROUP_INCLUDED
#define GROUP_INCLUDED
#include "Institution.h"
#include <vector>
class Group : public Institution
{
private:
    int group_id = 0;
    const Payer *group_payer = nullptr;
    bool has = false;
    std::string typeName = "Group";
   // std::vector<Person> data;

public:
    Group() = default;
    Group(std::string, bool);
    ~Group();
    void addGroupId();
    virtual bool has_member(Person, std::function<bool(int,int)>) const override;
    virtual const Payer *payer(const Payer *) override;
    virtual bool valid() const override;
    virtual Institution *clone() const override;
    int getIdGroup() const;
    //void addPerson(const Person &,std::function<bool(int,int)>);
    virtual const Payer *getPayer() const override;
    virtual std::string type() const override;
    virtual int count() const override;
    //virtual std::vector<Person> getData() const override;
    //virtual int countPersons() override;
};

#endif