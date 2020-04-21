#ifndef CH_ARR
#define CH_ARR

#include "Challange.hpp"
#include <functional>
class ChallangeArr
{
protected:
    Challange *arr;
    size_t size;

public:
    ChallangeArr();
    ChallangeArr(const Challange *arr, size_t size);
    ChallangeArr(const ChallangeArr &);
    ~ChallangeArr();
    Challange* getArr()const;
    size_t getSize()const;
    ChallangeArr &operator=(const ChallangeArr &);
    ChallangeArr &operator+=(const Challange &);
    ChallangeArr &add(const Challange &);
    Challange &operator[](int i);
    Challange operator[](int i) const;
    void printCArr(std::ostream&) ;
    void listByPopular();
    void listByNewest();
    void listByOldest();
};
#endif
