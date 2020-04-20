#include "Finish.h"

Finish::Finish()
{
    //this->data;
    this->id;
    this->tag = "";
    this->rating = 0;
}
Finish::Finish(const ChallangeArr &data, const char *tag, int id, double rating) : id(id), rating(rating)
{
    this->data = data;
    if (tag)
    {
        this->tag = new char[strlen(tag) + 1];
        strcpy(this->tag, tag);
    }
    //     for (size_t i = 0; i < this->data.getSize(); i++)
    // {
    //     if (strcmp(this->data[i].getTag(), tag) == 0)
    //     {
    //         for (size_t j = 0; j < this->data[i].getChallgedUser().getSize(); j++)
    //         {
    //             if (this->data[i].getChallgedUser()[j].getId() == id)
    //             {
    //                 this->data[i].getChallgedUser().operator-=(this->data[i].getChallgedUser()[j]);
    //                 this->data[i].setRating(rating);
    //             }
    //             this->data.printCArr();
    //             return;
    //         }
    //     }
    // }
    // this->data.printCArr();
}
Finish::Finish(const Finish &other) : id(other.id), rating(other.rating)
{
    this->data = other.data;
    if (other.tag)
    {
        delete[] this->tag;
        this->tag = new char[strlen(other.tag) + 1];
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
        this->tag = new char[strlen(other.tag) + 1];
        strcpy(this->tag, other.tag);
    }
    this->id = other.id;
    this->rating = other.rating;
    return *this;
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
    this->data = other;
}
void Finish::setTag(const char *tag)
{
    this->tag = new char[strlen(tag) + 1];
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
double Finish::getRating() const
{
    return this->rating;
}
ChallangeArr& Finish::RemoveChUsers(const char *tag, int id, double rating)
{
    for (size_t i = 0; i < this->data.getSize(); i++)
    {
        if (strcmp(this->data[i].getTag(), tag) == 0)
        {
            for (size_t j = 0; j < this->data[i].getChallgedUser().getSize(); j++)
            {
                if (this->data[i].getChallgedUser()[j].getId() == id)
                {
                    this->data[i].getChallgedUser().operator-=(this->data[i].getChallgedUser()[j]);
                    this->data[i].setRating(rating);
                  
                     return this->data;                 
                }
            }
            std::cout<<"THE "<<id<<" it's not challanged on Challange: "<<i<<"\n";
            return this->data;
        }
    }
   
  // this->data.printCArr();

    // this->data[0].getChallgedUser()[0];//getChallgedUser().operator[](0);
    //
}