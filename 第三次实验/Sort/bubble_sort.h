#ifndef _BUBBLE_SORT_
#define _BUBBLE_SORT_

#include "sort.h"

// 冒泡排序原始版：
template<typename T>
void Sort<T>::bubble_sort(vector<T> &data) {

    for (int i = 0; i < data.size() - 1; ++i) {
        for (int j = 0; j < data.size() - 1; ++j) {
            ++count_compare;
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                count_move += 3;
            }
        }
    }
}

// 冒泡排序优化版：
template<typename T>
void Sort<T>::bubble_sort_flag(vector<T> &data) {
    int flag = data.size();
    while (flag > 0) {
        int temp = 0;
        for (int i = 1; i < flag; ++i) {
            ++count_compare;
            if (data[i - 1] > data[i]) {
                swap(data[i - 1], data[i]);
                count_move += 3;
                temp = i;
            }
        }
        flag = temp;
    }
}

#endif // _BUBBLE_SORT_