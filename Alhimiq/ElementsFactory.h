#pragma once
#include "gold.h"
#include "philosopheStone.h"
#include "energy.h"
#include "spirit.h"
#include "stone.h"

class ElementsFactory
{

public:
    static Elements *readElements(std::istream &, std::string);
};
