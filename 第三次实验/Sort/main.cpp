//
// Created by lyk on 2021/6/3.
//

#include "sort.h"

using namespace std;

int main()
{
    int n = 1e4;
    int m = 100;
    vector<int> data_random(n); // 普通随机数据，取值范围是[0, n/2)
    vector<int> data_dense(n);  // 测试计数排序使用，含有大量随机重复数据的
    vector<int> data_a(n);      // ascending order 升序
    vector<int> data_de(n);     // descending order 降序

    for (int i = 0; i < n; i++)
    {
        data_random[i] = rand() % (n / 2);
        data_dense[i] = rand() % m;
        data_a[i] = i;
        data_de[i] = n - i - 1;
    }

    Sort<int> s;

    cout << "冒泡排序【原始版】：" << endl;
    s.timing_complex(s.bubble_sort, data_random, data_a, data_de, false, false);
    cout << "冒泡排序【优化版】：" << endl;
    s.timing_complex(s.bubble_sort_flag, data_random, data_a, data_de, false, false);

    cout << "直接插入排序：" << endl;
    s.timing_complex(s.strait_insert_sort, data_random, data_a, data_de, false, false);

    cout << "简单选择排序：" << endl;
    s.timing_complex(s.select_sort, data_random, data_a, data_de, false, false);

    cout << "希尔排序：" << endl;
    s.timing_complex(s.shell_sort, data_random, data_a, data_de, false, false);

    cout << "快速排序：" << endl;
    s.timing_complex(s.quick_sort, data_random, data_a, data_de, false, false);

    cout << "堆排序：" << endl;
    s.timing_complex(s.heap_sort, data_random, data_a, data_de, false, false);

    cout << "归并排序【递归实现】：" << endl;
    s.timing_complex(s.merge_sort, data_random, data_a, data_de, false, false);
    cout << "归并排序【非递归实现】：" << endl;
    s.timing_complex(s.merge_sort_NR, data_random, data_a, data_de, false, false);

    cout << "计数排序：" << endl;
    s.timing_complex(s.counting_sort, data_random, data_a, data_de, false, false);

    cout << "基数排序：" << endl;
    s.timing_complex(s.radix_sort, data_random, data_a, data_de, false, false);

    cout << "桶排序：" << endl;
    s.timing_complex(s.bucket_sort, data_random, data_a, data_de, false, false);

    return 0;
}