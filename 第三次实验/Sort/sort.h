//
// Created by lyk on 2021/6/3.
//

#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <limits.h>
#include <queue>

using namespace std;

template <typename T>
class Sort
{
private:
    static void _quick_sort(vector<T> &data, int left, int right);
    static void _merge_sort(vector<T> &data, vector<T> &temp, int left, int right);
    static void _merge(vector<T> &data, vector<T> &temp, int left, int right, int mid);
    static int max_length(vector<int> &data); // 返回整形数组中最大数据的位数
    static void heap_adjust(vector<T> &data, int start, int end);

public:
    void timing(vector<T> &data, void (*func)(vector<T> &d), bool show_result, bool check_sorted);
    void timing_complex(void (*func)(vector<T> &d), vector<T> &data_random, vector<T> &data_a, vector<T> &data_de, bool show_result, bool check_sorted);

    static void print(vector<T> &data);

    static void is_sorted(vector<T> &data);

    // 冒泡排序
    static void bubble_sort(vector<T> &data);
    static void bubble_sort_flag(vector<T> &data);

    // 直接插入排序
    static void strait_insert_sort(vector<T> &data);

    //简单选择排序
    static void select_sort(vector<T> &data);

    // 希尔排序
    static void shell_sort(vector<T> &data);

    // 快速排序
    static void quick_sort(vector<T> &data);

    // 堆排序
    static void heap_sort(vector<T> &data);

    // 归并排序
    static void merge_sort(vector<T> &data);    // 递归实现
    static void merge_sort_NR(vector<T> &data); // 非递归实现

    // 计数排序
    // 该接口只适用于 整形数组 的排序， 且仅当有大量重复数据时效率高
    static void _counting_sort(vector<int> &data, int low, int high);
    static void counting_sort(vector<int> &data);

    // 桶排序
    static void bucket_sort(vector<int> &data);

    // 基数排序
    // 该接口只适用于 正整数 的排序
    static void radix_sort(vector<int> &data);
};

#include "sort_implement.h"

// 直接插入排序：
template <typename T>
void Sort<T>::strait_insert_sort(vector<T> &data)
{
    int i, j;
    for (i = 1; i < data.size(); ++i)
    {
        if (data[i - 1] > data[i]) //如果出现逆序
        {
            T temp = data[i];
            for (j = i - 1; j >= 0 && data[j] > temp; --j)
            {
                data[j + 1] = data[j]; //向前移动
            }
            data[j + 1] = temp;
        }
    }
}

// 简单选择排序：
template <typename T>
void Sort<T>::select_sort(vector<T> &data)
{
    for (int i = 0; i < data.size(); ++i)
    {
        for (int j = i + 1; j < data.size(); ++j)
        {
            if (data[i] > data[j])
                swap(data[i], data[j]);
        }
    }
}

#endif // SORT_H
