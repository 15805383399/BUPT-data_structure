/*
 * @????: 
 * @��???: 
 * @����??: ??????
 * @Date: 2021-04-08 19:01:08
 * @LastEditTime: 2021-05-12 13:36:42
 */
using namespace std;
#include <iostream>
#include <vector>
#include <ctime>

class Solution
{
private:
    int n;
    vector<vector<int>> board;
    vector<vector<int>> check;
    vector<vector<vector<int>>> result;
    void solve(int x) //�����̵ĵ�x+1�н��м���
    {
        if (x == n)
        {
            // ���x==n ˵��n���ʺ��Ѿ�������ϣ��õ�һ�������õķ���
            result.push_back(board);
            return;
        }
        for (int y = 0; y < n; y++)
        {
            // ʹ�û��ݵķ���
            if (check[1][y] == 0 && check[2][x - y + n - 1] == 0 && check[3][x + y] == 0)
            //�ж��Ƿ���Է���
            {
                board[x][y] = check[1][y] = check[2][x - y + n - 1] = check[3][x + y] = 1;
                solve(x + 1); // ���ú����һ�н��м���
                board[x][y] = check[1][y] = check[2][x - y + n - 1] = check[3][x + y] = 0;
                // ����
            }
        }
    }

public:
    Solution(int _n)
    {
        n = _n;
        board = vector<vector<int>>(n, vector<int>(n, 0));
        check = {vector<int>(0, 0), vector<int>(n, 0),
                 vector<int>(2 * n - 1, 0), vector<int>(2 * n - 1, 0)};
    }

    vector<vector<vector<int>>> get_result()
    {
        // ����n�ʺ����н��ͬʱͳ������ʱ�䡣
        clock_t start, finish;
        double duration;
        start = clock();
        solve(0);
        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        cout << "duration is " << duration << endl;
        return result;
    }
};

int main()
{
    int n = 10;
    Solution a(n);
    vector<vector<vector<int>>> result = a.get_result();
    cout << n << "�ʺ�����һ����" << result.size() << "����" << endl;
    return 0;
}
