
#include <queue>
#include <iostream>
#include <utility>
#include <vector>
#include <string.h>
using namespace std;

struct edge
{
    int nxt; //指向上一条边
    int to;  //指向节点
};

class graph
{
private:
    void _DFS(int start);
    void _BFS(int start);
    void _paint(vector<int> &colors, int start, int &color_count);

public:
    int _size;          //最大规模
    int count;          //当前总边数
    vector<edge> edges; //从编号1开始使用
    vector<int> heads;  //每一个节点被连接的最后一条边的全局编号
    vector<bool> visited;
    graph(int max_size = 1e5);

    void add(int p, int q); // p 出发节点， q 指向节点
    void BFS(int start);
    void DFS(int start);
    void paint(vector<int> &colors);
};
graph::graph(int max_size)
{
    _size = max_size;
    count = 0;
    edges = vector<edge>(max_size);
    heads = vector<int>(max_size, 0);
    visited = vector<bool>(max_size, false);
}

void graph::add(int p, int q)
{                                  // p 出发节点， q 指向节点
    edges[++count].nxt = heads[p]; // 指向出发节点被出发的上一条边
    edges[count].to = q;           // 规定当前边指向的节点为q
    heads[p] = count;              // 更新当前出发节点出发的最后一条边为此边
}

void graph::DFS(int start)
{
    visited = vector<bool>(_size, false);
    cout << "深度优先搜索，从节点" << start << "开始：" << endl;
    _DFS(start);
    cout << endl;
}

void graph::_DFS(int start)
{
    cout << start << " ";
    visited[start] = true;
    for (int i = heads[start]; i != 0; i = edges[i].nxt)
    {
        int next_node = edges[i].to;
        if (!visited[next_node])
            _DFS(next_node);
    }
}

void graph::BFS(int start)
{
    visited = vector<bool>(_size, false);
    cout << "广度优先搜索，从节点" << start << "开始：" << endl;
    _BFS(start);
    cout << endl;
}

void graph::_BFS(int start)
{
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        visited[node] = true;
        for (int i = heads[node]; i != 0; i = edges[i].nxt)
        { // i 是边的编号
            if (!visited[edges[i].to])
                q.push(edges[i].to);
        }
    }
}

void graph::paint(vector<int> &colors)
{
    visited = vector<bool>(_size, false);
    int color_count = 0;
    for (int i = 1; i < colors.size(); i++)
    {
        _paint(colors, i, color_count);
        cout << i << "的颜色为：" << char('A' + colors[i]) << endl;
    }
}

void graph::_paint(vector<int> &colors, int start, int &color_count)
{
    if (visited[start])
        return;

    visited[start] = true; //更新访问记录
    vector<bool> color_use(color_count, false);
    for (int i = heads[start]; i != 0; i = edges[i].nxt)
    {
        int next_node = edges[i].to;
        if (visited[next_node])
            color_use[colors[next_node]] = true; //将这种颜色标记为true
    }
    bool add = true;
    for (int i = 0; i < color_count; i++)
    {
        if (color_use[i] == false) // 如果没有被占用
        {
            colors[start] = i;
            add = false;
            break;
        }
    }
    if (add == true)
    {
        colors[start] = color_count; // 将第一种颜色标号为0
        color_count += 1;
    }
}