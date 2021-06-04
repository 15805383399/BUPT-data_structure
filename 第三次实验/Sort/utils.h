
#ifndef _UTILS_
#define _UTILS_

#include "sort.h"

template<typename T>
void Sort<T>::timing(vector<T> &data, void (*func)(vector<T> &d), bool show_result, bool check_sorted) {
    count_move = 0; // 初始化
    count_compare = 0;

    vector<T> _data(data);
    clock_t start, finish;
    double duration;
    start = clock();
    func(_data);
    finish = clock();
    duration = (double) (finish - start) / CLOCKS_PER_SEC;
    cout << "\t比较次数 " << count_compare
         << "\t移动次数 " << count_move
         << "\t用时为 " << duration << "s" << endl;
    if (show_result) {
        cout << "排序结果为：";
        print(_data);
    }
    if (check_sorted) {
        is_sorted(_data);
    }
}

template<typename T>
void Sort<T>::timing_complex(void (*func)(vector<T> &d), vector<T> &data_random, vector<T> &data_a, vector<T> &data_de,
                             bool show_result, bool check_sorted) {
    cout << "  升序数据：";
    timing(data_a, func, show_result, check_sorted);
    cout << "  降序数据：";
    timing(data_de, func, show_result, check_sorted);
    cout << "  随机数据：";
    timing(data_random, func, show_result, check_sorted);
}

template<typename T>
void Sort<T>::print(vector<T> &data) {
    for (T e : data)
        cout << e << ' ';
    cout << endl;
}

template<typename T>
void Sort<T>::is_sorted(vector<T> &data) {
    for (int i = 0; i < data.size() - 1; ++i) {
        if (data[i] > data[i + 1]) {
            cout << "    无序" << endl;
            return;
        }
    }
    cout << "    有序" << endl;
}

#endif // _UTILS_