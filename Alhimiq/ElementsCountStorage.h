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
    ElementsCountStorage(const ElementsCountStorage&);
    ElementsCountStorage& operator=(const ElementsCountStorage&);
    ~ElementsCountStorage();
    ElementsCountStorage &addEl(const CountElements &);
    ElementsCountStorage &removeEl();
};
