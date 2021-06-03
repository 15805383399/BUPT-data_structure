
#ifndef _UTILS_
#define _UTILS_
#include "sort.h"
template <typename T>
void Sort<T>::timing(vector<T> &data, void (*func)(vector<T> &d), bool show_result)
{
    vector<T> _data(data);
    clock_t start, finish;
    double duration;
    start = clock();
    func(_data);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "    用时为 " << duration << "s" << endl;
    if (show_result)
    {
        cout << "    排序结果为：";
        print(_data);
        is_sorted(_data);
    }
}

template <typename T>
void Sort<T>::print(vector<T> &data)
{
    for (T e : data)
        cout << e << ' ';
    cout << endl;
}

template <typename T>
void Sort<T>::is_sorted(vector<T> &data)
{
    for (int i = 0; i < data.size() - 1; ++i)
    {
        if (data[i] > data[i + 1])
        {
            cout << "    无序" << endl;
            return;
        }
    }
    cout << "    有序" << endl;
}

#endif // _UTILS_