#ifndef _MERGE_SORT_
#define _MERGE_SORT_
#include "sort.h"
template <typename T>
void Sort<T>::merge_sort(vector<T> &data)
{
    vector<T> memory(data.size());
    _merge_sort(data, memory, 0, data.size() - 1);
}

template <typename T>
//为了方便起见，采用左闭右闭的区间表示
void Sort<T>::_merge_sort(vector<T> &data, vector<T> &temp, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + ((right - left) >> 1); //取中点
    // 采用分治的思想，递归地排序左右两个子序列

    _merge_sort(data, temp, left, mid);
    _merge_sort(data, temp, mid + 1, right);

    _merge(data, temp, left, right, mid);

    return;
}

template <typename T>
void Sort<T>::_merge(vector<T> &data, vector<T> &temp, int left, int right, int mid)
{
    int i = left, j = mid + 1;
    int count = 0;
    while (i <= mid && j <= right)
    {
        if (data[i] <= data[j])
            temp[count++] = data[i++];
        else
            temp[count++] = data[j++];
    }
    while (i <= mid)
        temp[count++] = data[i++];
    while (j <= mid)
        temp[count++] = data[j++];

    for (int t = 0; t < count; ++t)
    {
        data[left + t] = temp[t];
    }
    return;
}

template <typename T>
void Sort<T>::merge_sort_NR(vector<T> &data)
{
    if (data.size() < 2)
        return;
    vector<T> memory(data.size());
    int i;
    for (int gap = 1; gap < data.size(); gap *= 2)
    {
        for (i = 0; i + 2 * gap <= data.size(); i += 2 * gap)
        {
            int left = i, mid = i + gap - 1, right = i + 2 * gap - 1;
            _merge(data, memory, left, right, mid);
        }
        int left = i, mid = i + gap - 1, right = i + 2 * gap - 1;
        if (mid > data.size() - 1)
            mid = data.size() - 1;
        if (right > data.size() - 1)
            right = data.size() - 1;
        _merge(data, memory, left, right, mid);
    }
}
#endif // _MERGE_SORT_