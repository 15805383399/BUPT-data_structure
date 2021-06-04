#ifndef _HEAP_SORT_
#define _HEAP_SORT
#include "sort.h"

template <typename T>
void Sort<T>::heap_adjust(vector<T> &data, int start, int end)
{
    // 目标是大根堆
    // 定义 start, end 为左闭右开区间
    // i 节点的左右子节点分别为 2*i+1, 2*i+2
    T root_val = data[start];
    for (int i = 2 * start + 1; i < end; i = i * 2 + 1)
    {
        if (i < end - 1 && data[i] < data[i + 1])
            ++i;
        if (root_val >= data[i])
            break;
        data[start] = data[i];
        start = i;
    }
    data[start] = root_val;
}

template <typename T>
void Sort<T>::heap_sort(vector<T> &data)
{
    // 构建大根堆
    for (int i = data.size() / 2 - 1; i >= 0; --i)
        heap_adjust(data, i, data.size());

    for (int i = data.size() - 1; i > 0; --i)
    {
        swap(data[0], data[i]);
        heap_adjust(data, 0, i);
    }
}

#endif // _HEAP_SORT_