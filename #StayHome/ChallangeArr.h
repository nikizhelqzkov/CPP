#include "Challange.hpp"
class ChallangeArr
{
private:
Challange* arr;
int sustoqnie;
size_t size;
size_t Repeats;    

public:
    ChallangeArr();
    ChallangeArr(const Challange* arr,size_t size);
    ChallangeArr(const ChallangeArr&);
    ~ChallangeArr();
    ChallangeArr& operator=(const ChallangeArr&);
    ChallangeArr& operator+=(const Challange&);
    void lisrBy()

};

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