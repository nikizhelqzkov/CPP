#include "Organization.h"

// #include "Person.cpp"
// #include "Payer.cpp"
// #include "Institution.cpp"
// #include "Group.cpp"
// #include "Organization.cpp"

//g++ main.cpp Person.cpp Payer.cpp Institution.cpp Group.cpp Organization.cpp
int main()
{
    Person a("nikolay", true);
    Person a2("koko", true);
    Person a3("ivan", true);
    Person a4("kimon", true);
    Person a5("misho", true);
    Payer p("kozeel", 23);
    Payer p2("Ivan", 27);
    Payer p12("gosho", 37);

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
    std::cout << gr.getId() << " " << gr.has_member(a) << " " << gr.getPayer()->getName() << " " << gr.valid() << std::endl;
    gr.addPerson(a);

    Group gr2("kalqne", true);
    //td::cout<<a2.
    gr.addPerson(a2);
    std::cout << "proverka: " << gr.getData().size() << "\n";
    std::cout << "-------------\n";
    gr2.payer(&p2);
    gr2.addGroupId();
    gr2.addPerson(a3);
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
    gr4.addPerson(a4);
    gr4.addPerson(a5);
    gr5.payer(&p12);
    gr5.addGroupId();
    gr5.addPerson(a4);
    gr5.addPerson(a5);

    gr6.payer(&p2);
    gr6.addGroupId();
    gr6.addPerson(a3);
    gr7.payer(&p2);
    gr7.addGroupId();
    gr7.addPerson(a3);

    std::vector<Institution *> data2;
    if (gr6.valid())
        data2.push_back(&gr6);
    // if (gr3.valid())
    //     data2.push_back(&gr3);

    data2.push_back(&org);
    if (gr4.valid())
        data2.push_back(&gr4);

    if (gr5.valid())
        data2.push_back(&gr5);
    if (gr7.valid())
        data2.push_back(&gr7);
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
    std::cout << org2.compatible(org) << " " << org2.has_member(a) << " " << org2.type() << " " << std::endl;

    std::cout << "========================\n\n";
    Group gr8("kalqne", true);
    gr8.payer(&p);
    std::vector<Institution *> data3;
    if (org2.valid())
        data3.push_back(&org2);
    if (gr8.valid())
        data3.push_back(&gr8);
    Organization org3("kalqne", data3, "pichka dddddd");
    org3.payer(&p);
    std::cout << org3.getCountOfList() << std::endl;
    std::cout << org3.getPayer()->getName() << " " << org3.valid() << std::endl;
    std::cout << org3.compatible(org2) << " " << org3.has_member(a) << " " << org3.type() << " " << std::endl;

    return 0;
}