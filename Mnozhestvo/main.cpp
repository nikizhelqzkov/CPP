#include "Set.cpp"

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int ar[4] = {1, 4, 3, 5, };
    Set a(arr, 5);
    Set b(ar, 4);
    //a*=b;
    //Set b;
    // std::cout << *(a.end());
    //std::cout<<b.operator!();
    // a -= 3;
    // a.print();

    // std::cout<<(a>=b);
    std::cout << a;
}