#include "sortClass.h"

void SortClass::sort(EventArr &arr, size_t size, comparatorFunction func)
{
    for (size_t i = 0; i < size - 1; ++i)
    {
        for (size_t j = i + 1; j < size; ++j)
        {
            if (func(arr[i], arr[j]))
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}