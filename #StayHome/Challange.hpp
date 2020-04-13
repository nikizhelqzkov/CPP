#include "Challange.h"
//#include "PersonArr.h"

void  Contains(const char *name,const PersonArr& arr,  PersonArr res)
{

    for (size_t i = 0; i < arr.getSize(); i++)
    {
        if (strcmp(arr[i].getName(), name) == 0)
            res += arr[i];
      
    }
    
}
bool Contains(const char *name, PersonArr arr)
{

    for (size_t i = 0; i < arr.getSize(); i++)
    {
        if (strcmp(arr[i].getName(), name) == 0)

            return true;
    }
    return false;
}

Challange::Challange()
{
    this->User = nullptr;
    this->tag = nullptr;
    // this->ChallangedUser = nullptr;
    this->chUsers = nullptr;
    this->size = 0;
    this->users = nullptr;
}

Challange::Challange(const char *User, const char *tag, const PersonArr chUsers, PersonArr users)
{
    assert(Contains(User, users));
    this->User = new char[strlen(User) + 1];
    strcpy(this->User, User);
    assert(tag && strlen(tag) < 31);
    this->tag = new char[strlen(tag) + 1];
    strcpy(this->tag, tag);
    this->chUsers = chUsers;
    this->users = users;
    this->size = this->chUsers.getSize();
}
Challange::Challange(const Challange &other)
{
    this->User = new char[strlen(other.User) + 1];
    strcpy(this->User, other.User);
    this->tag = new char[strlen(other.tag) + 1];
    strcpy(this->tag, other.tag);
    this->chUsers = other.chUsers;
    this->users = other.users;
}
Challange::~Challange()
{
    delete[] this->User;
    delete[] this->tag;
}
Challange &Challange::operator=(const Challange &other)
{
    if (this != &other)
    {
        delete[] this->User;
        this->User = new char[strlen(other.User) + 1];
        strcpy(this->User, other.User);
        assert(other.tag);
        delete[] this->tag;
        this->tag = new char[strlen(other.tag) + 1];
        strcpy(this->tag, other.tag);
        this->chUsers = other.chUsers;
        this->users = other.users;
        this->size = this->chUsers.getSize();
    }
}
// void SetChallange(const char*, const char*);
void Challange::getChallgedUser() const
{
    this->chUsers.printArr();
}
char *Challange::getUser() const
{
    return this->User;
}
int Challange::getSize() const
{
    return this->size;
}