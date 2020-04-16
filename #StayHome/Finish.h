#ifndef FINISH_INCLUDED
#define FINISH_INCLUDED
#include "ChallangeArr.h"


class Finish
{
private:
    ChallangeArr data;
    int id;
    char* tag;
    double rating;
public:
    Finish();
    Finish(const ChallangeArr&,const char *,int ,int);
    Finish(const Finish&);
    ~Finish();
    Finish& operator=(const Finish&);
    void setId(double rating);
    void setData(const ChallangeArr&);
    void setTag(const char*);
    ChallangeArr getData()const;
    int getId()const;
    const char*getTag()const;
    double getRating()const;
    
};





#endif