//
// Created by lyk on 2021/6/3.
//
#pragma GCC optimize(3, "Ofast", "inline")

#include "sort.h"
#include <random>
#include "dispatch.h"

using namespace std;

int main() {
    int n = 3e4;
    int m = 100;
    vector<int> data_random(n); // 普通随机数据，取值范围是[0, n/2)
    vector<int> data_dense(n); // 测试计数排序使用，含有大量随机重复数据的
    vector<int> data_a(n);  // ascending order 升序
    vector<int> data_de(n); // descending order 降序

    default_random_engine e;
    uniform_int_distribution<int> u(0, n / 2);
    uniform_int_distribution<int> u_dense(0, m);

    for (int i = 0; i < n; i++) {
        data_random[i] = u(e);
        data_dense[i] = u_dense(e);
        data_a[i] = i;
        data_de[i] = n - i - 1;
    }

    Sort<int> s;
    cout << "基础实验：" << endl;
    cout << "冒泡排序【原始版】：" << endl;
    s.timing_complex(Sort<int>::bubble_sort, data_random, data_a, data_de, false,
                     false);
    cout << "冒泡排序【优化版】：" << endl;
    s.timing_complex(Sort<int>::bubble_sort_flag, data_random, data_a, data_de,
                     false, false);

    cout << "直接插入排序：" << endl;
    s.timing_complex(Sort<int>::strait_insert_sort, data_random, data_a, data_de,
                     false, false);

    cout << "简单选择排序：" << endl;
    s.timing_complex(Sort<int>::select_sort, data_random, data_a, data_de, false,
                     false);

    cout << "希尔排序：" << endl;
    s.timing_complex(Sort<int>::shell_sort, data_random, data_a, data_de, false,
                     false);

    cout << "快速排序：" << endl;
    s.timing_complex(Sort<int>::quick_sort, data_random, data_a, data_de, false,
                     false);

    cout << "堆排序：" << endl;
    s.timing_complex(Sort<int>::heap_sort, data_random, data_a, data_de, false,
                     false);

    cout << "归并排序【递归实现】：" << endl;
    s.timing_complex(Sort<int>::merge_sort, data_random, data_a, data_de, false,
                     false);
    cout << "归并排序【非递归实现】：" << endl;
    s.timing_complex(Sort<int>::merge_sort_NR, data_random, data_a, data_de,
                     false, false);

    cout << "计数排序：" << endl;
    s.timing_complex(Sort<int>::counting_sort, data_random, data_a, data_de,
                     false, false);

    cout << "基数排序：" << endl;
    s.timing_complex(Sort<int>::radix_sort, data_random, data_a, data_de, false,
                     false);

    cout << "桶排序：" << endl;
    s.timing_complex(Sort<int>::bucket_sort, data_random, data_a, data_de, false,
                     false);

    cout << "拓展试验——机器调度问题：" << endl;

    vector<double> tasks0 = {2, 14, 4, 16, 6, 5, 3};
    vector<double> tasks1(n);
    uniform_real_distribution<double> u_d(0, 100);
    for (int i = 0; i < n; ++i) {
        tasks1[i] = u_d(e);
    }
    cout << "默认测试数据：" << endl;
    dispatch(tasks0, 3);
    cout << "随机测试数据：" << endl;
    dispatch(tasks1, 10);
    return 0;
}