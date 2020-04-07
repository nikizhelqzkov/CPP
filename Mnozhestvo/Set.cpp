#include "Set.h"
#include <cassert>
bool isItNotRepeatable(int *arr, size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                return false;
            }
        }
    }
    return true;
}

Set::Set()
{
    this->arr = nullptr;
    this->size = 0;
}
Set::Set(int *arr, size_t size)
{
    assert(isItNotRepeatable(arr, size));
    this->size = size;
    this->arr = new int[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = arr[i];
    }
}
Set::Set(const Set &other)
{
    this->arr = other.arr;
    this->size = other.size;
}
int *Set::getArr() const
{
    return this->arr;
}
size_t Set::getSize() const
{
    return this->size;
}
void Set::setSet(const int *, size_t size)
{
    delete[] this->arr;
    this->size = size;
    this->arr = new int[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = arr[i];
    }
}
Set::~Set()
{
    delete[] this->arr;
}
int *Set::begin()
{
    return arr;
}
int *Set::end()
{
    return (this->arr + this->size - 1);
}
void Set::print()
{
    for (size_t i = 0; i < this->size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}
bool Set::operator()(int element) const
{
    for (size_t i = 0; i < this->size; i++)
    {
        if (this->arr[i] == element)
        {
            return true;
        }
    }
    return false;
}
bool Set::operator!()
{
    return this->arr == nullptr;
}
Set &Set::operator+=(int element)
{
    int *result;
    assert(this->size <= 149);
    result = new int[this->size + 1];
    for (size_t i = 0; i < this->size; i++)
    {
        result[i] = this->arr[i];
    }
    result[this->size] = element;
    this->size++;
    delete[] arr;
    arr = result;
    // delete[] result;
    return *this;
}
Set &Set::operator-=(int element)
{
    if (!(*this)(element))
        return *this;
    for (size_t i = 0; i < this->size - 1; i++)
    {
        if (arr[i] == element)
        {
            for (size_t j = i + 1; j < this->size; j++)
            {
                arr[j - 1] = arr[j];
            }
        }
    }
    if (arr[this->size - 1] == element)
    {
        arr[this->size - 1] == 0;
    }
    int *result;
    result = new int[this->size - 1];
    for (size_t i = 0; i < this->size - 1; i++)
    {
        result[i] = arr[i];
    }
    this->size--;
    delete[] arr;
    arr = result;
    //delete[] result;
    return *this;
}
void remove(int *arr, int element, size_t &size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        if (arr[i] == element)
        {
            for (size_t j = i + 1; j < size; j++)
            {
                arr[j - 1] = arr[j];
            }
        }
    }
    if (arr[size - 1] == element)
    {
        arr[size - 1] == 0;
    }
    size--;
}
Set &Set::operator+=(Set other)
{
    int *result;
    assert(this->size + other.size <= 150);
    result = new int[this->size + other.size];

    for (size_t i = 0; i < this->size; i++)
    {
        result[i] = this->arr[i];
    }
    size_t counter = 0;
    for (size_t i = this->size; i < this->size + other.size; i++)
    {
        result[i] = other.arr[counter];
        counter++;
    }
    this->size += other.size;
    delete[] this->arr;
    this->arr = result;
    // delete[] result;
    return *this;
}
Set &Set::operator-=(Set other)
{
    int *result;
    result = new int[this->size];
    size_t size = this->size;
    for (size_t i = 0; i < this->size; i++)
    {
        result[i] = arr[i];
    }

    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < other.size; j++)
        {
            if (this->arr[i] == other.arr[j])
            {
                remove(result, other.arr[i], size);
            }
        }
    }
    this->size = size;
    delete[] this->arr;
    this->arr = result;
    // delete[] result;
    return *this;
}

Set &Set::operator*=(const Set &other)
{

    for (size_t i = 0; i < this->size; i++)
    {
        if (!(other.operator()(this->arr[i])))
        {
            this->operator-=(this->arr[i]);
        }
    }
    return *this;
}
bool Set::operator==(const Set &other) const
{
    bool flag = false;
    if (this->size != other.size)
    {
        return false;
    }

    for (size_t i = 0; i < this->size; i++)
    {
        flag = false;
        for (size_t j = 0; j < this->size; j++)
        {
            if (this->arr[i] == other.arr[j])
            {
                flag = true;
            }
        }
        if (!flag)
        {
            return false;
        }
    }
    return true;
}
bool Set::operator!=(const Set &other) const
{

    if (this->operator==(other))
    {
        return false;
    }
    return true;
}
bool operator<=(const Set &first, const Set &second)
{
    bool flag = false;
    if (first.getSize() > second.getSize())
    {
        return false;
    }
    else if (first.getSize() == second.getSize())
    {
        return first == second;
    }
    else if (first.getSize() < second.getSize())
    {
        for (size_t i = 0; i < first.getSize(); i++)
        {
            flag = false;
            for (size_t j = 0; j < second.getSize(); j++)
            {
                if (first.getArr()[i] == second.getArr()[j])
                {
                    flag = true;
                }
            }
            if (!flag)
            {
                return false;
            }
        }
        return true;
    }
}
bool operator>=(const Set &first, const Set &second)
{
    bool flag = false;
    if (first.getSize() < second.getSize())
    {
        return false;
    }
    else if (first.getSize() == second.getSize())
    {
        return first == second;
    }
    else if (first.getSize() > second.getSize())
    {
        for (size_t i = 0; i < second.getSize(); i++)
        {
            flag = false;
            for (size_t j = 0; j < first.getSize(); j++)
            {
                if (second.getArr()[i] == first.getArr()[j])
                {
                    flag = true;
                }
            }
            if (!flag)
            {
                return false;
            }
        }
        return true;
    }
}
std::ostream &operator<<(std::ostream &out, Set &a)
{
    for (size_t i = 0; i < a.getSize(); i++)
    {
        out << a.getArr()[i] << ' ';
    }
    out << "\n";
}
