#include "ChallangeArr.h"

ChallangeArr::ChallangeArr()
{
    this->arr = nullptr;
    this->size = 0;
    this->Repeats = 0;
    this->sustoqnie = 0;
}
ChallangeArr::ChallangeArr(const Challange *arr, size_t size) : size(size)
{
    this->arr = new Challange[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = arr[i];
    }
}
ChallangeArr::ChallangeArr(const ChallangeArr &other) : size(other.size)
{
    this->arr = new Challange[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = arr[i];
    }
}
ChallangeArr::~ChallangeArr()
{
    delete[] this->arr;
}
ChallangeArr &ChallangeArr::operator=(const ChallangeArr &other)
{
    if (this != &other)
    {
        delete[] this->arr;
        this->size = other.size;
        this->arr = new Challange[this->size];
        for (size_t i = 0; i < this->size; i++)
        {
            this->arr[i] = arr[i];
        }
    }
    return *this;
}

