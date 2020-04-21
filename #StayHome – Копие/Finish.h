#ifndef FINISH_INCLUDED
#define FINISH_INCLUDED
#include "ChallangeArr.hpp"


class Finish
{
private:
    ChallangeArr data;
    int id;
    char* tag;
    double rating;
public:
    Finish();
    Finish(const ChallangeArr&,const char *,int ,double);
    Finish(const Finish&);
    ~Finish();
    Finish& operator=(const Finish&);
    void setId(int);
    void SetRating(double);
    void setData(const ChallangeArr&);
    void setTag(const char*);
    ChallangeArr getData()const;
    int getId()const;
    const char*getTag()const;
    double getRating()const;
    ChallangeArr& RemoveChUsers(const char* ,int ,double);
   
    
};





#endif