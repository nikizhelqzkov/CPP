#include <iostream>

#include "num.h"

NumberSummator::NumberSummator()
{
    this->sumOfNumbers = 0;
    this->count = 0;
}
NumberSummator::~NumberSummator()
{
    delete[] this->counters;
    this->count = 0;
}
NumberSummator::NumberSummator(const int sum)
{
    this->setSum(sum);
    this->count = 0;
}
int NumberSummator::getSum() const
{
    return this->sumOfNumbers;
}
size_t NumberSummator::getCount() const
{
    return this->count;
}
int *NumberSummator::getCounter() const
{
    return this->counters;
}
void NumberSummator::setSum(const int sum)
{
    this->sumOfNumbers = sum;
}
void NumberSummator::add(int other)
{
    if (this->count == 0)
    {
        this->count++;
        this->counters = new int[this->count];
    }

    else
    {
        this->count++;
    }
    this->counters[this->count - 1] = other;
    this->sumOfNumbers += other;
}
void NumberSummator::sub(int other)
{
    if (this->count == 0)
    {
        this->count++;
        this->counters = new int[this->count];
    }

    else
    {
        this->count++;
    }

    this->counters[this->count - 1] = other;
    this->sumOfNumbers -= other;
}
double NumberSummator::average()
{
    int sum = 0;
    for (size_t i = 0; i < this->count; i++)
    {
        sum += this->counters[i];
    }
    return sum / this->count;
}