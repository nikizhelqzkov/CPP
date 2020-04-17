#include "Finish.h"

Finish::Finish()
{
    this->data;
    this->id = 0;
    this->tag = nullptr;
    this->rating = 0;
}
Finish::Finish(const ChallangeArr &data, const char *tag, int id, double rating) : id(id), rating(rating)
{
    this->data = data;
    if (tag)
    {
        this->tag = new char[strlen(tag)];
        strcpy(this->tag, tag);
    }
}
Finish::Finish(const Finish &other) : id(other.id), rating(other.rating)
{
    this->data = other.data;
    if (other.tag)
    {
        delete[] this->tag;
        this->tag = new char[strlen(other.tag)];
        strcpy(this->tag, other.tag);
    }
}
Finish::~Finish()
{
    delete[] this->tag;
}
Finish &Finish::operator=(const Finish &other)
{
    this->data = other.data;
    if (other.tag)
    {
        delete[] this->tag;
        this->tag = new char[strlen(other.tag)];
        strcpy(this->tag, other.tag);
    }
    this->id = other.id;
    this->rating = other.rating;
}

void Finish::setId(int id)
{
    this->id = id;
}
void Finish::SetRating(double rating)
{
    this->rating = rating;
}
void Finish::setData(const ChallangeArr &other)
{
    this->data = data;
}
void Finish::setTag(const char *tag)
{
    this->tag = new char[strlen(tag)];
    strcpy(this->tag, tag);
}
ChallangeArr Finish::getData() const
{
    return this->data;
}
int Finish::getId() const
{
    return this->id;
}
const char *Finish::getTag() const
{
    return this->tag;
}
double Finish::getRating() const{
    return this->rating;
}