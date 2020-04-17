#ifndef FINISH_INCLUDED
#define FINISH_INCLUDED
#include "ChallangeArr.hpp"


class Finish//://public ChallangeArr
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
    void RemoveChUsers(const char* ,int ,double);
    //shte pravim funckiq koqto po idto shte namirra icha, shte go maha ot sistemata s chuseri 
    //a ako e edinstven , shte se maha challange  i shte se obnovqva reitinga na challange
    
};





#endif