#include "Challange.h"
//#include "PersonArr.h"

void Contains(const char *name, const PersonArr &arr, PersonArr res)
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
    this->Repeats = 0;
    this->position = 0;
}

Challange::Challange(const char *User, const char *tag, const PersonArr chUsers, PersonArr users):chUsers(chUsers),users(users)
{
    assert(Contains(User, users));
    //if (Contains(User, users))
    //{
        this->Repeats = 0;
        this->sustoqnie = 0;
    this->User = new char[strlen(User) + 1];
    strcpy(this->User, User);
    assert(tag && strlen(tag) < 31);
    this->tag = new char[strlen(tag) + 1];
    strcpy(this->tag, tag);
   
    this->size = this->chUsers.getSize();
    // }
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
    return *this;
}
// void SetChallange(const char*, const char*);
PersonArr Challange::getChallgedUser() const
{
    return this->chUsers;
}
char *Challange::getUser() const
{
    return this->User;
}
int Challange::getSize() const
{
    return this->size;
}
int Challange::getRepeats() const
{
    return this->Repeats;
}
int Challange::getPositions() const
{
    return this->position;
}
void Challange::setPosition(int position)
{
    this->position = position;
}
void Challange::setRepeats(int repeats)
{
    this->Repeats = repeats;
}
bool Challange::operator==(const Challange &other) const
{
    return strcmp(this->User, other.User) == 0 && strcmp(this->tag, other.tag) == 0;
}
void Challange::setChUsers(const PersonArr &other)
{
    this->chUsers = other;
    this->size = this->chUsers.getSize();
}
void Challange::setUser(const Person &other)
{
    this->chUsers += other;
    this->size++;
}
void Challange::printChallange() const
{
    std::cout << "User: " << this->User << " , Challange: #" << this->tag << ", Challanged Users: ";
    for (size_t i = 0; i < this->size; i++)
    {
        this->chUsers[i].print();
    }
    std::cout << " ,\n Repeats: " << this->Repeats;
}
// Challange *operator+=( Challange *buffer, const Challange &other)
// {
//     buffer = new Challange[1];
//     buffer[0] = other;
//     return buffer;
// }