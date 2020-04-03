#include <iostream>
#include <functional>
 std::function<int(int)>multi(int x){
     return [=](int a){return a*x;};
 }
int main()
{
   std::function<int(int)>mul =  multi(3);
    std::cout<<mul(5);
}