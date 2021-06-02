/*
 * @����: 
 * @�汾: 
 * @����: ���ȿ�
 * @Date: 2021-04-07 15:37:23
 * @LastEditTime: 2021-05-11 21:57:10
 */

using namespace std;
#include <iostream>
#include <vector>

int DFS(vector<vector<int>> &data, vector<vector<int>> &result, int x, int y, int num)
// ���������������
{
    // �жϱ߽�����
    if (x < 0 || y < 0 || x == data.size() || y == data[0].size() || data[x][y] == 0)
        return 0;
    int count = 1;

    data[x][y] = 0;
    result[x][y] = num;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < 4; ++i)
        count += DFS(data, result, x + dx[i], y + dy[i], num);

    return count;
}

vector<vector<int>> Connected(vector<vector<int>> data)
// ����ͳ����ͨ��
{
    int m = data.size(), n = data[0].size();
    int num = 1;
    vector<vector<int>> result(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (data[i][j] == 0)
                continue;
            int temp = DFS(data, result, i, j, num);

            cout << "�� " << num << " ����ͨ���СΪ��" << temp << endl;
            num += 1;
        }
    }
    return result;
}

void print(vector<vector<int>> &p)
{
    int m = p.size(), n = p[0].size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> data = {
        {1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1}};

    print(data);
    vector<vector<int>> result = Connected(data);
    print(result);
    return 0;
}