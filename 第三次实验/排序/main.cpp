//
// Created by lyk on 2021/6/3.
//

#include "sort.h"

using namespace std;

int main()
{
    int n = 1e4;
    int m = 100;
    vector<int> data0(n);
    vector<int> data1(n);

    for (int i = 0; i < n; i++)
    {
        data0[i] = rand() % (n / 2);
        data1[i] = rand() % m;
    }

    Sort<int> s;

    cout << "冒泡排序【原始版】：" << endl;
    s.timing(data0, s.bubble_sort, false);
    cout << "冒泡排序【优化版】：" << endl;
    s.timing(data0, s.bubble_sort_flag, false);

    cout << "直接插入排序：" << endl;
    s.timing(data0, s.strait_insert_sort, false);

    cout << "简单选择排序：" << endl;
    s.timing(data0, s.select_sort, false);

    cout << "希尔排序：" << endl;
    s.timing(data0, s.shell_sort, false);

    cout << "快速排序：" << endl;
    s.timing(data0, s.quick_sort, false);

    cout << "归并排序【递归实现】：" << endl;
    s.timing(data0, s.merge_sort, false);
    cout << "归并排序【非递归实现】：" << endl;
    s.timing(data0, s.merge_sort_NR, false);

    cout << "计数排序：" << endl;
    s.timing(data1, s.counting_sort, false);

    cout << "基数排序：" << endl;
    s.timing(data0, s.radix_sort, false);

    cout << "桶排序：" << endl;
    s.timing(data0, s.bucket_sort, false);

    cout << "堆排序：" << endl;
    s.timing(data0, s.heap_sort, false);

    return 0;
}