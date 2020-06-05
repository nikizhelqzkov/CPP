#include "Organization.h"

// #include "Person.cpp"
// #include "Payer.cpp"
// #include "Institution.cpp"
// #include "Group.cpp"
// #include "Organization.cpp"

//g++ main.cpp Person.cpp Payer.cpp Institution.cpp Group.cpp Organization.cpp

std::vector<Institution *> clear_institutions(std::vector<Institution *> data)
{
    std::vector<Institution *> temp;
    temp = data;
    for (int i = 0; i < temp.size(); ++i)
    {
        if (!temp[i]->valid())
        {
            temp.erase(temp.begin() + i);
        }
    }
    return temp;
}
std::string find_most_popular_institution(std::vector<Institution *> data)
{
    int max = 0;
    std::string result;
    for (int i = 0; i < data.size(); ++i)
    {
        if (data[i]->countPersons() > max)
        {
            max = data[i]->countPersons();
            result = "Type: " + data[i]->type() + " , ID : " + std::to_string(data[i]->getId()) + " , Payer name: " + data[i]->getPayer()->getName();
        }
    }
    return result;
}
bool p_rule(int p_id, int gr_id)
{
    return p_id == gr_id;
}
int main()
{
    Person a("nikolay", true);
    Person a2("koko", true);
    Person a3("ivan", true);
    Person a4("kimon", true);
    Person a5("misho", true);
    Payer p("kozeel", 23, p_rule);
    Payer p2("Ivan", 27, p_rule);
    Payer p12("gosho", 37, p_rule);

    std::cout << a.getName() << " " << a.getHasPayer() << std::endl;
    if (a.getHasPayer())
    {
        a.setId(p.getId());
    }
    if (a2.getHasPayer())
    {
        a2.setId(p.getId());
    }
    if (a3.getHasPayer())
    {
        a3.setId(p2.getId());
    }
    if (a4.getHasPayer())
    {
        a4.setId(p12.getId());
    }
    if (a5.getHasPayer())
    {
        a5.setId(p12.getId());
    }
    std::cout << a.getId() << "\n";
    std::cout << p.getName() << " " << p.getId() << std::endl;

    Group gr("kalqne", true);
    gr.payer(&p);

    gr.addGroupId();
    std::cout << gr.getId() << " " << gr.has_member(a, p_rule) << " " << gr.getPayer()->getName() << " " << gr.valid() << std::endl;
    gr.addPerson(a, p_rule);

    Group gr2("kalqne", true);
    //td::cout<<a2.
    gr.addPerson(a2, p_rule);
    std::cout << "proverka: " << gr.getData().size() << "\n";
    std::cout << "-------------\n";
    gr2.payer(&p2);
    gr2.addGroupId();
    gr2.addPerson(a3, p_rule);
    std::vector<Institution *> data;
    data.push_back(&gr);
    data.push_back(&gr2);
    Organization org("kalqne", data, "mquu bau str.");
    org.payer(&p);
    std::cout << org[1]->getPayer()->getName() << " " << org.valid() << std::endl;
    // Group gr3("kalqne", false);
    // std::cout << gr3.valid() << std::endl;
    // org.payer(&p2);
    std::cout << org.getPayer()->getName() << std::endl;
    std::cout << "========================\n\n";
    Group gr4("kalqne", true);
    Group gr5("kalqne", true);
    Group gr6("kalqne", true);
    Group gr7("kalqne", true);

    gr4.payer(&p12);
    gr4.addGroupId();
    gr4.addPerson(a4, p_rule);
    gr4.addPerson(a5, p_rule);
    gr5.payer(&p12);
    gr5.addGroupId();
    gr5.addPerson(a4, p_rule);
    gr5.addPerson(a5, p_rule);

    gr6.payer(&p2);
    gr6.addGroupId();
    gr6.addPerson(a3, p_rule);
    gr7.payer(&p2);
    gr7.addGroupId();
    gr7.addPerson(a3, p_rule);

    std::vector<Institution *> data2;
    if (gr6.valid())
    {
        data2.push_back(&gr6);
    }
    // if (gr3.valid())
    //     data2.push_back(&gr3);

    data2.push_back(&org);
    if (gr4.valid())
    {
        data2.push_back(&gr4);
    }

    if (gr5.valid())
    {
        data2.push_back(&gr5);
    }
    if (gr7.valid())
    {
        data2.push_back(&gr7);
    }
    std::cout << "=================count\n\n";
    for (Institution *data : data2)
    {
        std::cout << data->type() << " " << data->getPayer()->getId() << " " << data->getData().size() << " ";
    }
    std::cout << "\n";
    Organization org2("kalqne", data2, "kozludi 2");
    std::cout << org2.getCountOfList() << std::endl;
    org2.payer(&p2);
    std::cout << org2.getPayer()->getName() << " " << org2.valid() << std::endl;
    std::cout << org2.compatible(org) << " " << org2.has_member(a, p_rule) << " " << org2.type() << " " << std::endl;

    std::cout << "========================\n\n";
    Group gr8("kalqne", true);
    gr8.payer(&p);
    gr8.addGroupId();
    std::vector<Institution *> data3;
    if (org2.valid())
    {
        data3.push_back(&org2);
    }
    if (gr8.valid())
    {
        data3.push_back(&gr8);
    }

    std::cout << "-------------\n\n";
    for (Institution *data : org2.getList())
    {
        std::cout << data->type() << " " << data->getPayer()->getId() << " " << data->getData().size() << " ";
    }

    Organization org3("kalqne", data3, "pichka dddddd");
    org3.payer(&p);
    std::cout << org3.getCountOfList() << std::endl;
    std::cout << org3.getPayer()->getName() << " " << org3.valid() << std::endl;
    std::cout << org3.compatible(org2) << " " << org3.has_member(a, p_rule) << " " << org3.type() << " " << std::endl;

    std::cout << "===========-=-------new part------============\n\n";

    std::cout << org3.getList().size() << "\n";
    org3.add_institution(&gr);
    std::cout << org3.getList().size() << "\n";
    org3.add_institution(&gr5);
    std::cout << org3.getList().size() << "\n";

    std::cout << "++++++++++++++++++++++++++++++\n\n";
    std::vector<Institution *> list;
    Group notValid("kalqne", false);
    Group notValid2("kalqne", false);
    list.push_back(&org3);
    list.push_back(&org2);
    list.push_back(&gr5);
    list.push_back(&notValid2);
    list.push_back(&gr7);
    list.push_back(&notValid);

    std::cout << list.size() << std::endl;

    std::cout << "_____________clear institution__________________\n\n";
    std::cout << "Old Institution list size: " << list.size() << "\n";
    std::vector<Institution *> newList;
    newList = clear_institutions(list);
    std::cout << "CLEARED Institution list size: " << newList.size() << std::endl;

    std::cout << "+-+-+--+-+-+-+-+-+-+-+\n\n";

    std::cout << org3.getId() << "\n";
    std::cout << org2.getId() << "\n";

    std::cout << "--+-+-+-+-+-+----\n\n";
    for (Institution *l : newList)
    {
        std::cout << l->getId() << " ";
    }
    std::cout << "\n-------------\n\n";
    std::cout << org2.countPersons() << "\n";
    std::cout << org3.countPersons() << "\n";

    std::cout << "_____________________________find most popular__________________________________\n\n";

    std::cout << find_most_popular_institution(newList) << "\n";
    return 0;
}