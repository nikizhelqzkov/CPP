#include "PersonArr.h"

PersonArr::PersonArr(const Person *arr = nullptr, size_t size = 0) : size(size)
{
    // assert(arr && size > 0);
    this->arr = new Person[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = arr[i];
    }
}
PersonArr::PersonArr(const PersonArr &other)
{
    this->size = other.size;
    this->arr = new Person[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = other.arr[i];
    }
}
PersonArr::~PersonArr()
{
    delete[] this->arr;
}
PersonArr &PersonArr::operator=(const PersonArr &other)
{
    if (this != &other)
    {
        this->SetArr(other.arr, other.size);
    }
    return *this;
}
void PersonArr::SetArr(const Person *arr, size_t size)
{
    //assert(arr && size >= 0);
    delete[] this->arr;
    this->size = size;
    this->arr = new Person[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = arr[i];
    }
}
const Person *PersonArr::getArr() const //const
{
    return this->arr;
}
size_t PersonArr::getSize() const
{
    return this->size;
}
void PersonArr::printArr(std::ostream &out)
{
    for (size_t i = 0; i < this->size; i++)
    {
     this->arr[i].profile_info(this->arr[i].getName());
    }
}
Person &PersonArr::operator[](int i)
{
    return this->arr[i];
}
Person PersonArr::operator[](int i) const
{
    return this->arr[i];
}
PersonArr &PersonArr::operator+=(const Person &other)
{

    Person *buffer;
    buffer = new Person[this->size + 1];
    for (size_t i = 0; i < this->size; i++)
    {
        buffer[i] = this->arr[i];
    }
    buffer[this->size] = other;
    delete[] this->arr;
    this->size++;
    this->arr = new Person[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = buffer[i];
    }
    delete[] buffer;
    return *this;
}
PersonArr &PersonArr::operator-=(const Person &element)
{
    Person *buffer;
    bool flag = false;
    buffer = new Person[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        buffer[i] = this->arr[i];
    }

    for (size_t i = 0; i < this->size - 1; i++)
    {
        if (buffer[i] == element)
        {
            flag = true;
            for (size_t j = i + 1; j < this->size; j++)
            {
                buffer[j - 1] = this->arr[j];
            }
            break;
        }
    }
    if (buffer[this->size - 1] == element)
    {
        flag = true;
    }
    if (!flag)
    {
        return *this;
    }
    this->size--;
    delete[] this->arr;
    this->arr = new Person[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = buffer[i];
    }
    delete[] buffer;
    return *this;
}