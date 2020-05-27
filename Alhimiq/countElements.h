#pragma once
#include <string>
class CountElements
{
private:
    std::string name{};
    int count{1};
     bool isItEmpty();
public:
    CountElements() = default;
    CountElements(std::string,int);
    CountElements(const CountElements&);
    CountElements& operator=(const CountElements&);
    ~CountElements();
    std::string getName()const;
    int getCount()const;
    void setCount(int);
    bool getIsItEmpty();
};


