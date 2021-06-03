
#ifndef _QUICK_SORT_
#define _QUICK_SORT_
#include "sort.h"

template <typename T>
void Sort<T>::quick_sort(vector<T> &data)
{
    _quick_sort(data, 0, data.size() - 1);
}

template <typename T>
//为了方便起见，采用左闭右闭的区间表示
void Sort<T>::_quick_sort(vector<T> &data, int left, int right)
{
    if (left == right)
        return;
    int low = left, high = right;
    T pivot = data[left];
    while (left < right)
    {
        while (pivot < data[right] && left < right)
            --right;
        data[left] = data[right];
        while (data[left] <= pivot && left < right)
            ++left;
        data[right] = data[left];
    }
    data[left] = pivot;
    if (low < left - 1)
        _quick_sort(data, low, left - 1);
    if (right + 1 < high)
        _quick_sort(data, right + 1, high);
    return;
}

#endif // _QUICK_SORT_