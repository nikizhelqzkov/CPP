#include "Challange.h"
//#include "PersonArr.h"

void Contains(const char *name, const PersonArr &arr, PersonArr &res)
{

    for (size_t i = 0; i < arr.getSize(); i++)
    {
        if (strcmp(arr[i].getName(), name) == 0)
            res += arr[i];
    }
}
bool Contains(const char *name, const PersonArr &arr)
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
    this->users = nullptr; //!
    this->Repeats = 0;
    this->position = 0;
    this->sustoqnie = 0;
    this->posInArr = 0;
    this->rating = 0;
}

Challange::Challange(const char *User, const char *tag, const PersonArr &chUsers, const PersonArr &users) : chUsers(chUsers), users(users)
{
    assert(Contains(User, users));
    //if (Contains(User, users))
    //{
    this->posInArr = 0;
    this->Repeats = 0;
    this->User = new char[strlen(User) + 1];
    strcpy(this->User, User);
    assert(tag && strlen(tag) < 31);
    this->tag = new char[strlen(tag) + 1];
    strcpy(this->tag, tag);
    this->sustoqnie = 0;
    this->size = this->chUsers.getSize();
    this->rating = 0;
    // }
}
Challange::Challange(const Challange &other) : chUsers(other.chUsers), users(other.users),
                                               rating(other.rating), sustoqnie(other.sustoqnie), Repeats(other.Repeats), size(other.size), posInArr(other.posInArr), position(position)
{
    if (this->User)
    {
        this->User = new char[strlen(other.User) + 1];
        strcpy(this->User, other.User);
    }
    if (this->tag)
    {
        this->tag = new char[strlen(other.tag) + 1];
        strcpy(this->tag, other.tag);
    }
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
        this->Repeats = other.Repeats;
        this->sustoqnie = other.sustoqnie;
        this->posInArr = other.posInArr;
        this->rating = other.rating;
    }
    return *this;
}
// void SetChallange(const char*, const char*);
PersonArr Challange::getChallgedUser() const
{
    return this->chUsers;
}
PersonArr &Challange::getChallgedUser()
{
    return this->chUsers;
}
const char *Challange::getUser() const
{
    return this->User;
}
int Challange::getSize() const
{
    return this->size;
}
const char *Challange::getTag() const
{
    return this->tag;
}
int Challange::getRepeats() const
{
    return this->Repeats;
}
int Challange::getPositions() const
{
    return this->position;
}
int Challange::getSustoqnie() const
{
    return this->sustoqnie;
}
void Challange::setPosition(int position)
{
    this->position = position;
}
void Challange::setTag(const char *tag)
{
    this->tag = new char[strlen(tag) + 1];
    strcpy(this->tag, tag);
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
    std::cout << "User: " << this->User << " , Challange: #" << this->tag;

    if (this->sustoqnie == 0)
    {
        std::cout << " , Sustoqnie: New, ";
    }
    else if (this->sustoqnie > 0 && this->sustoqnie < 10)
    {
        std::cout << " , Sustoqnie: quite recently, ";
    }
    else if (this->sustoqnie >= 10)
    {
        std::cout << " , Sustoqnie: old, ";
    }
    std::cout << "Rating: " << this->rating;
    std::cout << " ,\n Repeats: " << this->Repeats<< ", Challanged Users: ";;
    for (size_t i = 0; i < this->size; i++)
    {
        this->chUsers[i].print();
    }
}
void Challange::setSustoqnie(int s)
{
    assert(s < 3 && s >= 0);
    this->sustoqnie = s;
}

void Challange::setPosInArr(int i)
{
    this->posInArr = i;
}
int Challange::getPosInArr() const
{
    return this->posInArr;
}
void Challange::setRating(double rating)
{
    assert(rating >= -5 && rating <= 10);
    if (this->rating == 0)
    {
        this->rating = rating;
    }
    else
    {
        this->rating = (this->rating + rating) / 2;
    }
}
// Challange::Challange(const char *user, const char *tag)
// {
//     if (user)
//     {
//         this->User = new char[strlen(user)];
//         strcpy(User, user);
//     }
//     if (tag)
//     {
//         this->tag = new char[strlen(tag)];
//         strcpy(this->tag, tag);
//     }
//     this->chUsers = nullptr;
//     this->posInArr = 0;
//     this->size = 0;
//     this->sustoqnie = 0;
//     this->users = nullptr;
// }
void Challange::setChInPerson(const char *user, const char *tag)
{

    if (user)
    {
        delete[] this->User;
        this->User = new char[strlen(user)];
        strcpy(User, user);
    }
    if (tag)
    {
        delete[] this->tag;
        this->tag = new char[strlen(tag)];
        strcpy(this->tag, tag);
    }
    this->chUsers = nullptr;
    this->posInArr = 0;
    this->size = 0;
    this->sustoqnie = 0;
    this->users = nullptr;
    // this->rating = 0;
}
// Challange *operator+=( Challange *buffer, const Challange &other)
// {
//     buffer = new Challange[1];
//     buffer[0] = other;
//     return buffer;
// }