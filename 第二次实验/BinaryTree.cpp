/*
 * @描述: 
 * @版本: 
 * @作者: 廖奕凯
 * @Date: 2021-05-24 06:42:18
 * @LastEditTime: 2021-06-02 03:26:53
 */

#include <queue>
#include <iostream>
#include <utility>
using namespace std;

struct BinNode
{
    char data;
    BinNode *l_child = NULL;
    BinNode *r_child = NULL;
    BinNode *parent = NULL;
};

class BinTree
{
private:
    void remove(BinNode *p);

public:
    BinNode *root;
    BinTree(char data[], int n);
    ~BinTree();

    void preTrav(BinNode *p);
    void inTrav(BinNode *p);
    void postTrav(BinNode *p);
    void levelTrav();
    void road(char c);
};

BinTree::BinTree(char data[], int n)
{
    // 非递归构造
    // left_child 2*i+1, right_child 2*i+2
    queue<pair<BinNode *, int>> q;
    BinNode *p1 = new BinNode;
    p1->data = data[0];
    root = p1;
    q.push(make_pair(p1, 0));

    while (!q.empty())
    {
        BinNode *p2 = q.front().first; //从队列中读取首位的BinNode
        int i = q.front().second;      //从队列中读取首位的位置编号
        q.pop();

        if (2 * i + 1 < n && data[2 * i + 1] != NULL)
        { // 如果左子节点存在
            p1 = new BinNode;
            p1->data = data[2 * i + 1];
            p2->l_child = p1;
            q.push(make_pair(p1, 2 * i + 1));
        }

        if (2 * i + 2 < n && data[2 * i + 2] != NULL)
        { // 如果右子节点存在
            p1 = new BinNode;
            p1->data = data[2 * i + 2];
            p2->r_child = p1;
            q.push(make_pair(p1, 2 * i + 2));
        }
    }
}

void BinTree::remove(BinNode *p)
{ // 递归地删除节点
    if (p == NULL)
        return;
    remove(p->l_child);
    remove(p->r_child);
    delete p;
}

BinTree::~BinTree()
{
    remove(root);
}

void BinTree::preTrav(BinNode *p)
{ // 前序历遍
    if (p == NULL)
        return;
    cout << p->data << " ";
    preTrav(p->l_child);
    preTrav(p->r_child);
}

void BinTree::inTrav(BinNode *p)
{ // 中序历遍
    if (p == NULL)
        return;
    inTrav(p->l_child);
    cout << p->data << " ";
    inTrav(p->r_child);
}

void BinTree::postTrav(BinNode *p)
{ // 后序历遍
    if (p == NULL)
        return;
    postTrav(p->l_child);
    postTrav(p->r_child);
    cout << p->data << " ";
}

void BinTree::levelTrav()
{ // 层序历遍
    cout << "层序历遍：" << endl;
    if (root == NULL)
        return;
    BinNode *p;
    queue<BinNode *> q;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << p->data << " ";
        if (p->l_child != NULL)
            q.push(p->l_child);
        if (p->r_child != NULL)
            q.push(p->r_child);
    }
    cout << endl;
}

int main()
{
    const int n = 10;
    char data[n];
    for (int i = 0; i < n; ++i)
    {
        data[i] = 'a' + i;
    }
    BinTree tree(data, n);
    tree.levelTrav();

    cout << "前序历遍：" << endl;
    tree.preTrav(tree.root);
    cout << endl;

    cout << "中序历遍：" << endl;
    tree.inTrav(tree.root);
    cout << endl;

    cout << "后序历遍：" << endl;
    tree.postTrav(tree.root);
    cout << endl;
}