#pragma once
#include <cassert>
#include <cstring>
#include <iostream>
class Employ
{
private:
    char *name{};
    size_t workExp;

protected:
    Employ() = default;
    Employ(const char *, size_t);
    Employ(const Employ &);
    Employ &operator=(const Employ &);
    virtual void printOwn() const {};

public:
    void setName(const char *_name);
    void setWorkExp(size_t workExp);
    const char *getName() const;
    size_t getWorkExp() const;
    ~Employ();
    void print() const;
   virtual Employ **removeEmploy(Employ *arr[], size_t size);
};
