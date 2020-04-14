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
    int sustoqnie;

public:
    Challange();
    Challange(const char *, const char *, const PersonArr, const PersonArr);
    Challange(const Challange &);
    ~Challange();
    Challange &operator=(const Challange &);
    void SetChallange(const char *, const char *);
    PersonArr getChallgedUser() const;
    char *getUser() const;
    int getSize() const;
    int getRepeats()const;
    int getPositions()const;
    void setPosition(int);
    void setRepeats(int);
    bool operator==(const Challange&)const;
    void setChUsers(const PersonArr&);
    void setUser(const Person&);
    void printChallange()const;
  //friend  Challange* operator+=( Challange *,const Challange&);

};
