#include "Organization.h"

// #include "Person.cpp"
// #include "Payer.cpp"
// #include "Institution.cpp"
// #include "Group.cpp"
// #include "Organization.cpp"

//g++ main.cpp Person.cpp Payer.cpp Institution.cpp Group.cpp Organization.cpp

bool hasMemberInInstitution(std::function<bool(int, int)> f, Person p, Institution *i)
{
    return i->has_member(p, f);
}
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
/*std::string find_most_popular_institution(std::vector<Institution *> data)
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
}*/
std::string find_most_popular_institution(std::vector<Institution *> data, std::vector<Person> p)
{
    int max = 0, current = 0;
    std::string result = "";
    for (int i = 0; i < data.size(); ++i)
    {
        current = 0;
        for (int j = 0; j < p.size(); ++j)
        {
            if (hasMemberInInstitution(data[i]->getPayer()->getRule(), p[j], data[i]))
            {
                current++;
            }
        }
        if (current > max)
        {
            max = current;
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
    /*
    Vie koito gledate tova da znaete slednoto:
    90% ot komentarite postaveni v koda sa zashtoto imah vtori variant za rabota na poslednata funkciq chrez 
    vector ot hora i napravih mnogo gotini funckii i gi ostavih za da se poglednat. 
    Poischistih meina ot izhodi i ostavih izhoda na dvete vunshni funkcii. 
    Za momenta sum slozhil samo edno pravilo kato razbira se moje da ima i poveche. 
    Napravil sum ierarhiq organizaciq sudurzhashta organizaciq sudurzhashta organizaciq i t.n i grupi
    Mnogo e priqtno kato umeesh da rabotish s nasledqvane i polimorfizum :)
    */
    Person a("nikolay", true);
    Person a2("koko", true);
    Person a3("ivan", true);
    Person a4("kimon", true);
    Person a5("misho", true);
    Payer p("kozeel", 23, p_rule);
    Payer p2("Ivan", 27, p_rule);
    Payer p12("gosho", 37, p_rule);
    Group gr("kalqne", true);
    Group gr2("kalqne", true);
    Group gr4("kalqne", true);
    Group gr5("kalqne", true);
    Group gr6("kalqne", true);
    Group gr7("kalqne", true);
    Group gr8("kalqne", true);

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

    gr.payer(&p);

    gr.addGroupId();
    //gr.addPerson(a, p_rule);

    //td::cout<<a2.
    // gr.addPerson(a2, p_rule);
    //std::cout << "proverka: " << gr.getData().size() << "\n";
    gr2.payer(&p2);
    gr2.addGroupId();
    //gr2.addPerson(a3, p_rule);
    std::vector<Institution *> data;
    data.push_back(&gr);
    data.push_back(&gr2);
    Organization org("kalqne", data, "mquu bau str.");
    org.payer(&p);

    gr4.payer(&p12);
    gr4.addGroupId();
    //  gr4.addPerson(a4, p_rule);
    // gr4.addPerson(a5, p_rule);
    gr5.payer(&p12);
    gr5.addGroupId();
    //  gr5.addPerson(a4, p_rule);
    //  gr5.addPerson(a5, p_rule);

    gr6.payer(&p2);
    gr6.addGroupId();
    // gr6.addPerson(a3, p_rule);
    gr7.payer(&p2);
    gr7.addGroupId();
    // gr7.addPerson(a3, p_rule);

    std::vector<Institution *> data2;
    if (gr6.valid())
    {
        data2.push_back(&gr6);
    }

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
    // std::cout << "=================count\n\n";
    // for (Institution *data : data2)
    // {
    //     std::cout << data->type() << " " << data->getPayer()->getId() << " " << data->getData().size() << " ";
    // }

    Organization org2("kalqne", data2, "kozludi 2");

    org2.payer(&p2);

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

    // for (Institution *data : org2.getList())
    // {
    //     std::cout << data->type() << " " << data->getPayer()->getId() << " " << data->getData().size() << " ";
    // }

    Organization org3("kalqne", data3, "pichka dddddd");
    org3.payer(&p);

    org3.add_institution(&gr);

    org3.add_institution(&gr5);

    std::vector<Institution *> list;
    Group notValid("kalqne", false);
    Group notValid2("kalqne", false);
    list.push_back(&org3);
    list.push_back(&org2);
    list.push_back(&gr5);
    list.push_back(&notValid2);
    list.push_back(&gr7);
    list.push_back(&notValid);

    std::cout << "\n____________________________clear institution___________________________________\n\n";
    std::cout << "Old Institution list size: " << list.size() << "\n";
    std::vector<Institution *> newList;
    newList = clear_institutions(list);
    std::cout << "CLEARED Institution list size: " << newList.size() << std::endl;

    // std::cout << "+-+-+--+-+-+-+-+-+-+-+\n\n";

    // std::cout << org3.getId() << "\n";
    // std::cout << org2.getId() << "\n";

    // std::cout << "--+-+-+-+-+-+----\n\n";
    // for (Institution *l : newList)
    // {
    //     std::cout << l->getId() << " ";
    // }
    // std::cout << "\n-------------\n\n";
    // std::cout << org2.countPersons() << "\n";
    // std::cout << org3.countPersons() << "\n";

    // std::cout << "_____________________________find most popular__________________________________\n\n";

    // std::cout << find_most_popular_institution(newList) << "\n";

    std::cout << "\n_____________________________find most popular__________________________________\n\n";
    std::vector<Person> person_data{a, a2, a3, a4, a5};
    std::cout << find_most_popular_institution(newList, person_data)<<std::endl;
    return 0;
}