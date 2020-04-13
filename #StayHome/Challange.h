#include "PersonArr.h"
#include <cstring>

class Challange
{
private:
   // char * ChallangedUser;

    char* User;
    char* tag;
    PersonArr users;
    int size;
    PersonArr chUsers;
   
public:
    Challange(); 
    Challange(const char*,const char*,const PersonArr ,const PersonArr );
    Challange(const Challange&);
    ~Challange();
    Challange& operator=(const Challange&);
    void SetChallange(const char*, const char*);
    void getChallgedUser()const;
    char* getUser()const;
    int getSize()const;
};

