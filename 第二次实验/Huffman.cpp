/*
 * @ĂčĘö: 
 * @°ćąž: 
 * @×÷Őß: ÁÎŢČż­
 * @Date: 2021-05-24 15:57:25
 * @LastEditTime: 2021-05-24 16:03:43
 */

#include <queue>
#include <iostream>
#include <utility>
#include <map>
using namespace std;
/*
    哈夫曼树是度相同的树中带权路径（WPL）最短的树
    满二叉树不一定是二叉树
    权值越大的叶离根越近
    1. 构造森林全是根
    2. 选用两小造新树
    3. 删除两小填新人
    4. 重复2 3 剩单根
    * 自底向上构造
    * 贪心算法
    * 哈夫曼树中只有度为0 和度为2 的节点，没有度为1 的节点
    * n 个叶，合并n-1 次，因此总共具有2n-1 个节点
    * 叶的度为0 ，其余度为2
    
    在选取权值最小的两个节点的过程中需要用到最小堆
    
*/

struct HNode
{
    int weight;
    HNode *l_child = NULL;
    HNode *r_child = NULL;
    HNode *parent = NULL;
    HNode(int w, HNode *l = NULL, HNode *r = NULL, HNode *p = NULL)
        : weight(w), l_child(l), r_child(r), parent(p) {}
};

struct cmp
{
    // 定义 > ，将权值小的放在堆顶
    bool operator()(const HNode *a, const HNode *b)
    {
        return a->weight > b->weight;
    }
};
class Huffman
{
private:
    vector<int> counts;
    vector<string> code_book;
    vector<HNode *> leafs;
    map<HNode *, char> code_map;
    HNode *_root;
    void _init();
    void char_count(string &txt);
    void build_tree();
    void build_code_book();
    HNode *_check(HNode *p, string &result);

public:
    Huffman() { _init(); }
    Huffman(string &txt);
    void print_code();

    string encode(string &txt);
    string decode(string &codes);
};

Huffman::Huffman(string &txt)
{
    _init();
    encode(txt);
}

void Huffman::_init()
{
    counts = vector<int>(256, 0);
    code_book = vector<string>(256, "");
    code_map.clear();
    _root = NULL;
    leafs = vector<HNode *>(256, NULL);

    // cout << "初始化完毕" << endl;
}

string Huffman::encode(string &txt)
{
    cout << "编码文本为：" << endl;
    cout << txt << endl;
    // cout << "开始编码" << endl;

    char_count(txt);
    build_tree();
    build_code_book();

    string result = "";
    for (char c : txt)
        result += code_book[int(c)];

    cout << "编码结果为：" << endl;
    cout << result << endl;
    return result;
}

void Huffman::char_count(string &txt)
{
    _init(); //现将统计向量初始化
    for (char c : txt)
    {

        counts[int(c)] += 1;
    }
    // cout << "字频统计完毕" << endl;
}

void Huffman::build_tree()
{
    priority_queue<HNode *, vector<HNode *>, cmp> q;

    // leafs 已经被初始化为全NULL vector
    for (int i = 0; i < 256; ++i)
    {

        if (counts[i] == 0)
            continue;

        HNode *temp = new HNode(counts[i]);
        leafs[i] = temp;
        q.push(leafs[i]);
        code_map[temp] = char(i);
    }
    // cout << "leafs构建完毕" << endl;
    HNode *a, *b, *temp;
    while (q.size() > 1)
    {
        // 从堆顶取出权重最小的两个节点
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        // 将两个节点作为孩子，构造其共同的父节点，父节点的权重为a、b的权重和
        temp = new HNode(a->weight + b->weight, a, b);
        // 设置a b 的父节点
        a->parent = temp;
        b->parent = temp;
        q.push(temp);
    }
    _root = q.top(); // 保存根节点，便于后续历遍
    cout << "哈夫曼树构建完毕" << endl;
}

void Huffman::build_code_book()
{
    // 所有编码默认初始化为""
    // 未被统计到的字符保持默认编码
    for (int i = 0; i < 256; i++)
    {
        // 跳过不存在的字符
        if (counts[i] == 0)
            continue;
        HNode *p = leafs[i];
        string code = "";
        // 从叶开始，返回根节点，统计路径
        while (p->parent != NULL)
        {
            if (p == p->parent->l_child)
                code = "0" + code;
            else
                code = "1" + code;

            p = p->parent;
        }
        code_book[i] = code;
    }
}

string Huffman::decode(string &codes)
{
    HNode *p = _root;
    string result = "";
    for (char c : codes)
    {
        p = _check(p, result);
        if (c == '0')
            p = p->l_child;
        else
            p = p->r_child;
    }
    p = _check(p, result);
    cout << "解码结果为：" << endl;
    cout << result << endl;
    return result;
}

HNode *Huffman::_check(HNode *p, string &result)
{
    if (p->l_child == NULL)
    {
        // 没有子节点，说明当前节点为叶
        if (code_map.count(p) == 0)
            cout << "不在统计范围内" << endl;
        else
            result += string(1, code_map[p]);
        return _root;
    }
    else
        return p;
}

void Huffman::print_code()
{
    cout << "编码表为：" << endl;
    for (int i = 0; i < code_book.size(); ++i)
    {
        if (code_book[i] == "")
            continue;
        cout << char(i) << " : " << code_book[i] << endl;
    }
}
int main()
{
    string txt = "I love BUPT, forever!";
    txt = "Make me thy lyre, even as the forest is:\nWhat if my leaves are falling like its own!\nThe tumult of thy mighty harmonies,\nWill take from both a deep, autumnal tone,\nSweet though in sadness. Be thou, Spirit fierce,\nMy spirit! Be thou me, impetuous one!\nDrive my dead thoughts over the universe,\nLike wither'd leaves to quicken a new birth!\nAnd, by the incantation of this verse,\nScatter, as from an unextinguish'd hearth,\nAshes and sparks, my words among mankind!\nBe through my lips to unawaken'd earth,\nThe trumpet of a prophecy! Oh Wind,\nIf Winter comes, can Spring be far behind?";
    Huffman huf;
    string codes = huf.encode(txt);
    huf.print_code();
    string result = huf.decode(codes);
    cout << "压缩率：" << float(codes.size()) / float(8 * txt.size()) << endl;
    ;
    return 0;
}