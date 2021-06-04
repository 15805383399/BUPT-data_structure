#ifndef _SHELL_SORT_
#define _SHELL_SORT_

#include "sort.h"

// 希尔排序：
template<typename T>
void Sort<T>::shell_sort(vector<T> &data) {
    int interval = data.size() / 2;
    int i, j;
    while (interval >= 1) {
        for (i = interval; i < data.size(); ++i) {
            ++count_compare;
            if (data[i] < data[i - interval]) {
                T temp = data[i];
                for (j = i - interval; j >= 0 && data[j] > temp;
                     j -= interval, ++count_compare) {
                    data[j + interval] = data[j];
                    ++count_move;
                }
                data[j + interval] = temp;
                count_move += 2;
            }
        }
        interval /= 2;
    }
}

#endif // _SHELL_SORT_