/*
 * @描述: 
 * @版本: 
 * @作者: 廖奕凯
 * @Date: 2021-05-31 10:05:27
 * @LastEditTime: 2021-06-02 03:22:27
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge
{
    int from, to, weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

class MSTree
{
private:
    int node_num;
    int edge_num;
    vector<Edge> edges;
    vector<int> fathers;
    int find_root(int node);

public:
    MSTree(int n, vector<vector<int>> data);

    void build_tree();
};

MSTree::MSTree(int n, vector<vector<int>> data)
{
    node_num = n + 1;
    edge_num = data.size();
    for (int i = 0; i < data.size(); i++)
    {
        edges.push_back(Edge(data[i][0],
                             data[i][1],
                             data[i][2]));
    }
    fathers = vector<int>(node_num);
    for (int i = 0; i < node_num; i++)
        fathers[i] = i; // 初始化时，自己时自己的father
}

int MSTree::find_root(int node)
{
    if (fathers[node] != node)
        return find_root(fathers[node]);
    else
        return node;
}

bool cmp(Edge &a, Edge &b) { return a.weight < b.weight; }

void MSTree::build_tree()
{
    sort(edges.begin(), edges.end(), cmp);
    int total = 0;
    for (int i = 0; i < edge_num; i++)
    {
        int root_f = find_root(edges[i].from);
        int root_t = find_root(edges[i].to);
        if (root_f != root_t)
        {
            fathers[root_t] = root_f;
            total += edges[i].weight;
            cout << edges[i].from
                 << "  ->  "
                 << edges[i].to
                 << "  weight:"
                 << edges[i].weight
                 << endl;
        }
    }
    cout << "带权路径和为：" << total << endl;
}
int main()
{
    vector<vector<int>> data = {{1, 3, 7},
                                {1, 2, 6},
                                {1, 4, 5},
                                {2, 3, 4},
                                {2, 4, 4},
                                {2, 5, 2},
                                {3, 5, 3},
                                {4, 5, 10}};
    //  {from, to, weight}
    MSTree mstree(5, data);
    mstree.build_tree();
    return 0;
}
