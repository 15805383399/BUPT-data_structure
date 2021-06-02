/*
 * @描述: 
 * @版本: 
 * @作者: 廖奕凯
 * @Date: 2021-05-24 16:02:44
 * @LastEditTime: 2021-05-24 16:03:24
 */
#include "graph.h"
using namespace std;

int main()
{
    cout << "请输入：" << endl;
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;
    //cout<<num_nodes<<" "<<num_edges<<endl;
    graph g(100);

    for (int i = 0; i < num_edges; i++)
    {
        int p, q;
        cin >> p >> q;
        //cout<<p<<q<<endl;
        g.add(p, q);
    }
    cout << "图构建完毕" << endl;
    g.BFS(1);
    g.DFS(2);
    return 0;
}
/*
8 9
1 8  
1 2
1 3
2 4
3 5
3 6
4 5
4 6
5 7
*/