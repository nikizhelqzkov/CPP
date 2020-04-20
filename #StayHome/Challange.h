#ifndef CH_INCLUDED
#define CH_INCLUDED

#include "PersonArr.hpp"
#include <cstring>

class Challange
{
protected:
    // char * ChallangedUser;

    char *User;
    char *tag;
    PersonArr users;
    int size;
    PersonArr chUsers;
    int Repeats;
    int position;
    int sustoqnie;//0->new;1->quite recently; 2->old
    int posInArr;
    double rating;

public:
    Challange();
    Challange(const char *, const char *, const PersonArr&, const PersonArr&);
    Challange(const Challange &);
    ~Challange();
    Challange &operator=(const Challange &);
    void SetChallange(const char *, const char *);
    PersonArr getChallgedUser() const;
    PersonArr& getChallgedUser();

    const char *getUser() const;
    const char* getTag()const;
    int getSize() const;
    int getRepeats()const;
    int getPositions()const;
    int getSustoqnie()const;
    int getPosInArr()const;
    void setPosition(int);
    void setRepeats(int);
    void setTag(const char*);
    void setSustoqnie(int);
    bool operator==(const Challange&)const;
    void setChUsers(const PersonArr&);
    void setUser(const Person&);
    void setPosInArr(int);
    void setRating(double);
    void printChallange(std::ostream& out);
  //friend  Challange* operator+=( Challange *,const Challange&);
  Challange(const char*, const char*);
  void setChInPerson(const char*, const char*);
};
#endif