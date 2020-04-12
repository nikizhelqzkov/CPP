#include "PersonArr.h"
class Challange
{
private:
    char * ChallangedUser;
    char* User;
    PersonArr users;
    int size;
    PersonArr chUsers;
   
public:
    Challange(); bool Contains(const char*);
    Challange(const char* User,const char* ChallangedUsers,const PersonArr users);
    Challange(const Challange&);
    ~Challange();
    Challange& operator=(const Challange&);
    void SetChallange(const char*, const char*);
    char* getChallgedUser()const;
    char* getUser()const;
    int getSize()const;
};

