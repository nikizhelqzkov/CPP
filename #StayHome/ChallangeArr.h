#ifndef CH_ARR
#define CH_ARR

#include "Challange.hpp"
#include <functional>
class ChallangeArr : public Challange
{
private:
    Challange *arr;
    size_t size;

public:
    ChallangeArr();
    ChallangeArr(const Challange *arr, size_t size);
    ChallangeArr(const ChallangeArr &);
    ~ChallangeArr();
    ChallangeArr &operator=(const ChallangeArr &);
    ChallangeArr &operator+=(const Challange &);
    ChallangeArr &add(const Challange &);
    ChallangeArr &operator[](int i);
    ChallangeArr operator[](int i) const;
    void printCArr() const;
    void listByPopular();
    void listByNewest();
    void listByOldest();
};
#endif
//+= s proverka ako sushtestvuva da ne go dobawq a vdigne broqch
//sustoqniq (1)1-new , 2-10(2) qiite recently, 11+ - old(3)
//using comparatorFunction = std::function<bool(Student,Student)>;
// /void sort(Student* arr, size_t size, comparatorFunction func)
// {
//     for(size_t i=0; i < size - 1; ++i)
//     {
//         for(size_t j = i + 1; j<size; ++j)
//         {
//             if(func(arr[i], arr[j]))
//             {
//                 std::swap(arr[i], arr[j]);
//             }
//         }
//     }
// }
// sort(arr, size, [] (Student a,Student b) { return a.fn > b.fn; });