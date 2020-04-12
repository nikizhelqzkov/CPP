#include "Challange.h"
#include "PersonArr.h"

bool Contains(const char *name, PersonArr arr)
{

    for (size_t i = 0; i < arr.getSize(); i++)
    {
        if (strcmp(arr[i].getName(), name) == 0)
            return true;
    }
    return false;
}

//  Challange::Challange(){
//      this->User = nullptr;
//      this->ChallangedUser = nullptr;
//  }

// Challange(const char* User,const char* ChallangedUsers,const PersonArr* users);
// Challange(const Challange&);
// ~Challange();
// Challange& operator=(const Challange&);
// void SetChallange(const char*, const char*);
// char* getChallgedUser()const;
// char* getUser()const;
// int getSize()const;