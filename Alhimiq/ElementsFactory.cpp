#include "ElementsFactory.h"

Elements *ElementsFactory::readElements(std::istream &in, std::string str)
{
    if (str == "Air")
    {
        return Air::read(in);
    }
    if (str == "Earth")
    {
        return Earth::read(in);
    }
    if (str == "Energy")
    {
        return Energy::read(in);
    }
    if (str == "Fire")
    {
        return Fire::read(in);
    }
    if (str == "Gold")
    {
        return Gold::read(in);
    }

    if (str == "Metal")
    {
        return Metal::read(in);
    }
    if (str == "Philosopher's Stone")
    {
        return PS::read(in);
    }
    if (str == "Spirit")
    {
        return Spirit::read(in);
    }
    if (str == "Stone")
    {
        return Stone::read(in);
    }
    if (str == "Water")
    {
        return Water::read(in);
    }
}