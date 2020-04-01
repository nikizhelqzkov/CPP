#ifndef NUM_H_INCLUDED
#define NUM_H_INCLUDED

#include <iostream>
#include <cmath>

class NumberSummator
{
private:
    int sumOfNumbers;
    int *counters;
    size_t count;

public:
    NumberSummator();
    NumberSummator(const int);
    ~NumberSummator();
    void setSum(const int);
    int getSum() const;
    size_t getCount() const;
    int *getCounter() const;
    void add(int other);
    void sub(int other);
    double average();
};

#endif