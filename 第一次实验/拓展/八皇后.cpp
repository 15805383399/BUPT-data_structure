/*
 * @????: 
 * @°???: 
 * @×÷??: ??????
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
    void solve(int x) //对棋盘的第x+1行进行计算
    {
        if (x == n)
        {
            // 如果x==n 说明n个皇后已经放置完毕，得到一个可以用的方案
            result.push_back(board);
            return;
        }
        for (int y = 0; y < n; y++)
        {
            // 使用回溯的方法
            if (check[1][y] == 0 && check[2][x - y + n - 1] == 0 && check[3][x + y] == 0)
            //判断是否可以放置
            {
                board[x][y] = check[1][y] = check[2][x - y + n - 1] = check[3][x + y] = 1;
                solve(x + 1); // 放置后对下一行进行计算
                board[x][y] = check[1][y] = check[2][x - y + n - 1] = check[3][x + y] = 0;
                // 回溯
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
        // 计算n皇后所有解的同时统计运行时间。
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
    cout << n << "皇后问题一共有" << result.size() << "个解" << endl;
    return 0;
}
