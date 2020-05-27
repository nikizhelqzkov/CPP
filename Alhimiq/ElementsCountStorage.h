#pragma once
#include "countElements.h"
#include <vector>
class ElementsCountStorage
{
private:
    std::vector<CountElements> data{};

public:
    ElementsCountStorage() = default;
    ElementsCountStorage(std::vector<CountElements>);
    ElementsCountStorage(const ElementsCountStorage &);
    ElementsCountStorage &operator=(const ElementsCountStorage &);
    ~ElementsCountStorage();
    ElementsCountStorage &operator+=(const CountElements &);
    ElementsCountStorage &removeEl();
    std::vector<CountElements> getData() const;
    void setCountEl(int,int);

};
