/*
 * @描述: 
 * @版本: 
 * @作者: 廖奕凯
 * @Date: 2021-05-24 16:04:15
 * @LastEditTime: 2021-05-24 16:04:16
 */

#include "graph.h"
using namespace std;

int main()
{
    cout << "请输入：" << endl;
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    graph g(100);
    for (int i = 0; i < num_edges; i++)
    {
        int p, q;
        cin >> p >> q;
        g.add(p, q);
    }

    vector<int> colors(num_nodes + 1, 0); // 以边的编号为索引
    g.paint(colors);
    return 0;
}

/*
7 19
1 2
1 3
1 4
1 5
1 6
1 7
2 1
2 3
3 1
3 2
3 4
4 1
4 3
5 1
5 3
5 6
6 1
6 5
7 1
*/