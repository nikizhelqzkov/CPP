#include "Institution.h"

Institution::Institution(std::string name) : name(name) {}
Institution::~Institution() {}
void Institution::setId(int id)
{
    this->id = id;
}
int Institution::getId()const{
    return this->id;
}