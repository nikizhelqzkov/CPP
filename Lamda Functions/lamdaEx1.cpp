#include <iostream>
#include <functional>

using fn = std::function<int(int)>;
using ffn = std::function<fn(int)>;
template <class T>
using vFn = std::function<void(T &)>;
template <class T>
using TFn = std::function<T(T &)>;
template <class T, class K>
using TsFn = std::function<K(T &)>;
fn multi(int x)
{
    return [x](int a) -> int { return a * x; };
}

ffn f(int a)
{
    return [=](int x) {
        return [x, a](int y) -> int {
            return a * x * y;
        };
    };
}

fn defideFrom(int a)
{
    return [a](int x) -> int { return a / x; };
}
fn defideBy(int a)
{
    return [a](int x) -> int { return x / a; };
}
ffn devideFromFn(int a)
{
    return [a](int x) {
        return [a, x](int y) -> int { return a / x / y; };
    };
}
template <class T>
void forEach(T *arr, size_t size, vFn<T> f)
{
    for (size_t i = 0; i < size; i++)
    {
        f(arr[i]);
    }
}
template <class T, class K>
K *map(T *arr, size_t size, TsFn<T, K> a)
{
    K *res = new K[size];
    for (size_t i = 0; i < size; i++)
    {
        res[i] = a(arr[i]);
    }
    return res;
}

// double* map(int*arr,size_t size,std::function<double(int)>a){
//     double* res = new double[size];
//     for (size_t i = 0; i < size; i++)
//     {
//         res[i] =a(arr[i]);
//     }
//     return res;

// }
template <class T>

T reduce(T arr[],
         size_t size,
         std::function<void(T &, const T &)> f)
{
    T result = 0;

    for (size_t i = 0; i < size; i++)
        f(result, arr[i]);

    return result;
}
template <class T>
class vectors
{
private:
    T *arr;
    size_t size;

public:
    vectors();
    vectors(T *arr, size_t size);
    ~vectors();
    T *getData() const;
    size_t getSize() const;
};
template <class T>
vectors<T>::vectors()
{
    this->arr = nullptr;
    this->size = 0;
}
template <class T>
vectors<T>::vectors(T *arr, size_t size)
{
    this->size = size;
    this->arr = new T[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->arr[i] = arr[i];
    }
}

template <class T>
vectors<T>::~vectors()
{
    delete[] this->arr;
}
template <class T>
T *vectors<T>::getData() const
{
    return this->arr;
}
template <class T>
size_t vectors<T>::getSize() const
{
    return this->size;
}
int main()
{
    // ffn a = devideFromFn(25);
    // std::cout << a(5)(4);
    // std::function<int(int)> mul = multi(3);
    //std::cout << mul(5);

    int arr[5] = {1, 2, 3, 4, 5};
    size_t size = 5;
    vectors<int> v(arr, size);

    forEach<int>(v.getData(), v.getSize(), [](const int &a) { std::cout << a << ' '; });
    double *res = map<int, double>(v.getData(), v.getSize(), [](const int &a) { return 0.5 + a; });

    forEach<double>(res, size, [](const double &a) { std::cout << a << ' '; });
    std::cout << reduce<int>(v.getData(), v.getSize(), [](int &acc, const int &val) {
        acc += val;
    });
}