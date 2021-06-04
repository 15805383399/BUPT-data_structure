#ifndef BUCKET_SORT_
#define BUCKET_SORT_
#include "sort.h"

/*
 * 包含使用桶排序思想的排序方法
 * 基数排序，基数排序，桶排序
 */
template <typename T>
void Sort<T>::_counting_sort(vector<int> &data, int low, int high)
{ // low high 代表数组中最小和最大的元素
    vector<int> counts(high - low + 1);
    for (int num : data)
        counts[num - low] += 1;

    int index = 0;
    for (int i = 0; i < counts.size(); ++i)
    {
        for (int j = 0; j < counts[i]; ++j)
            data[index++] = low + i;
    }
}
template <typename T>
void Sort<T>::counting_sort(vector<int> &data)
{
    int low = INT_MAX, high = INT_MIN;
    for (int num : data)
    {
        low = min(low, num);
        high = max(high, num);
    }
    _counting_sort(data, low, high);
}

template <typename T>
int Sort<T>::max_length(vector<int> &data)
{
    int high = data[0];
    for (int num : data)
        high = max(high, num);
    int count = 0;
    while (high != 0)
    {
        high /= 10;
        count++;
    }
    return count;
}

template <typename T>
void Sort<T>::radix_sort(vector<int> &data)
{
    int max_l = max_length(data);
    vector<int> counts(10);
    vector<int> temp(data.size());
    int radix = 1;
    for (int i = 0; i < max_l; ++i)
    {
        for (int j = 0; j < 10; ++j)
            counts[j] = 0; // 归零计数器

        for (int num : data) // 统计出现次数
            counts[(num / radix) % 10] += 1;

        for (int j = 1; j < 10; ++j) // 计算每个bucket 数组中对应的位置上界
            counts[j] += counts[j - 1];

        for (int j = data.size() - 1; j >= 0; --j)
        {
            int k = (data[j] / radix) % 10;
            temp[--counts[k]] = data[j];
        }
        for (int j = 0; j < data.size(); ++j)
            data[j] = temp[j];
        radix *= 10;
    }
}

template <typename T>
void Sort<T>::bucket_sort(vector<int> &data)
{
    int low = INT_MAX, high = INT_MIN;
    for (int num : data)
    {
        low = min(low, num);
        high = max(high, num);
    }

    int bucket_num = data.size() / 50;
    bucket_num = max(100, bucket_num);
    double space = double(high - low + 1) / bucket_num;
    vector<list<int>> buckets(bucket_num, list<int>(1, INT_MIN));
    int j = 0;
    for (int num : data)
    {

        int k = (num - low) / space;

        list<int>::iterator it = --buckets[k].end();

        while (*it > num)
            --it;
        buckets[k].insert(++it, num);
    }

    int count = 0;
    for (int i = 0; i < bucket_num; ++i)
    {
        if (buckets[i].size() == 0)
            continue;
        for (list<int>::iterator it = ++buckets[i].begin(); it != buckets[i].end(); ++it)
            data[count++] = *it;
    }
}
#endif // _BUCKET_SORT_