#include "ChallangeArr.h"
void swap(Challange &a, Challange &b)
{
    Challange g;
    g = a;
    a = b;
    b = g;
}
void listBy(Challange *arr, size_t size, std::function<bool(Challange, Challange)> func)
{
    for (size_t i = 0; i < size - 1; ++i)
    {
        for (size_t j = i + 1; j < size; ++j)
        {
            if (func(arr[i], arr[j]))
            {

                Challange g;
                g = arr[i];
                arr[i] = arr[j];
                arr[j] = g;
                // std::swap(arr[i], arr[j]);
                // swap(arr[i],arr[j]);
            }
        }
    }
}

ChallangeArr::ChallangeArr()
{
    this->arr = nullptr;
    this->size = 0;
}
ChallangeArr::ChallangeArr(const Challange *arr, size_t size) : size(size)
{
    this->arr = new Challange[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = arr[i];
        this->arr[i].setPosInArr(i);
    }
}
ChallangeArr::ChallangeArr(const ChallangeArr &other) : size(other.size)
{
    this->arr = new Challange[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = other.arr[i];
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
            this->arr[i] = other.arr[i];
        }
    }
    return *this;
}
ChallangeArr &ChallangeArr::operator+=(const Challange &other)
{
    Challange *buffer;
    buffer = new Challange[this->size + 1];
    for (size_t i = 0; i < this->size; i++)
    {
        buffer[i] = this->arr[i];
    }
    buffer[this->size] = other;
    delete[] this->arr;
    this->size++;
    this->arr = new Challange[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = buffer[i];
    }
    delete[] buffer;
    return *this;
}
Challange &ChallangeArr::operator[](int i)
{
    return this->arr[i];
}
Challange ChallangeArr::operator[](int i) const
{
    return this->arr[i];
}
Challange *ChallangeArr::getArr() const
{
    return this->arr;
}
size_t ChallangeArr::getSize() const
{
    return this->size;
}
ChallangeArr &ChallangeArr::add(const Challange &other)
{
    int sz = this->size;
    for (size_t i = 0; i < sz; i++)
    {
        if (this->arr[i] == other)
        {

            // for (size_t j = 0; j < other.getChallgedUser().getSize(); j++)
            // {
            //     if (!Contains(other.getChallgedUser().operator[](j).getName(), this->arr[i].getChallgedUser()))
            //     {
            //
            //     }
            // }
            //  Challange a;
            //  a = this->arr[i];
            //a.printChallange();

            this->arr[i].setUser(other.getChallgedUser().operator[](0));
            // this->arr[i] = a;
            //a.printChallange();
            this->arr[i].setChUsers(other.getChallgedUser());
            this->arr[i].setRepeats(this->arr[i].getRepeats() + 1);
            if (this->arr[i].getRepeats() == 0)
            {
                this->arr[i].setSustoqnie(0);
            }
            else if (this->arr[i].getRepeats() > 0 && this->arr[i].getRepeats() < 10 && this->arr[i].getSustoqnie() == 0)
            {
                this->arr[i].setSustoqnie(1);
            }
            else if (this->arr[i].getRepeats() >= 10 && this->arr[i].getSustoqnie() == 1)
            {
                this->arr[i].setSustoqnie(2);
            }

            return *this;
        }
        else
        {
            if (this->arr[i].getRepeats() == 0)
            {
                this->arr[i].setSustoqnie(0);
            }
            else if (this->arr[i].getRepeats() > 0 && this->arr[i].getRepeats() < 10)
            {
                this->arr[i].setSustoqnie(1);
            }
            else if (this->arr[i].getRepeats() >= 10)
            {
                this->arr[i].setSustoqnie(2);
            }
        }

        //this->size++;
    }

    *this += other;
    return *this;
}

void ChallangeArr::printCArr() const
{
    for (size_t i = 0; i < this->size; i++)
    {
        std::cout << "Challange " << i << " : ";
        this->arr[i].printChallange();
        std::cout << "\n";
    }
}
void ChallangeArr::listByPopular()
{

    listBy(this->arr, this->size, [](Challange a, Challange b) { return a.getRepeats() < b.getRepeats(); });
    this->printCArr();
}

void ChallangeArr::listByNewest()
{

    listBy(this->arr, this->size, [](Challange a, Challange b) { return a.getPosInArr() > b.getPosInArr(); });
    this->printCArr();
}

void ChallangeArr::listByOldest()
{

    listBy(this->arr, this->size, [](Challange a, Challange b) { return a.getPosInArr() < b.getPosInArr(); });
    this->printCArr();
}
