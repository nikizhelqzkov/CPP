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

public:
    Challange();
    Challange(const char *, const char *, const PersonArr&, const PersonArr&);
    Challange(const Challange &);
    ~Challange();
    Challange &operator=(const Challange &);
    void SetChallange(const char *, const char *);
    PersonArr getChallgedUser() const;
    const char *getUser() const;
    int getSize() const;
    int getRepeats()const;
    int getPositions()const;
    int getSustoqnie()const;
    int getPosInArr()const;
    void setPosition(int);
    void setRepeats(int);
    void setSustoqnie(int);
    bool operator==(const Challange&)const;
    void setChUsers(const PersonArr&);
    void setUser(const Person&);
    void setPosInArr(int);
    void printChallange()const;
  //friend  Challange* operator+=( Challange *,const Challange&);

};
