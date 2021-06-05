//
// Created by lyk on 2021/6/4.
//

#ifndef SORT_DISPATCH_H
#define SORT_DISPATCH_H

#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include<functional>

typedef pair<int, int> P;

struct cmp {
    // 1 表示机器编号
    // 2 表示当前任务长度
    bool operator()(P &a, P &b) {
        return a.second > b.second; // 小值优先
    }
};


void dispatch(vector<double> &tasks, int machine_num) {
    // 输出原始任务列表
    cout << "任务：" << endl;
    for (auto task : tasks)
        cout << task << " ";
    cout << endl;
    sort(tasks.begin(), tasks.end(), greater<int>());
    vector<vector<double>> dispatch_list(machine_num);
    vector<double> times_list(machine_num, 0); // 用于储存每个机器的任务总时长

    priority_queue<P, vector<P>, cmp> q;
    for (int i = 1; i < machine_num; ++i) {
        q.push(P(i, 0)); // 所有机器的初始工作时长都为0
    }
    int this_machine = 0; // 当前机器编号
    double longest = 0;
    for (double task : tasks) {
        if (times_list[this_machine] + task > longest) {
            q.push(P(this_machine, times_list[this_machine]));
            this_machine = q.top().first; // 取出当前时长最短的机器
            q.pop();
        }
        times_list[this_machine] += task; // 分配工作
        dispatch_list[this_machine].emplace_back(task);
        longest = max(longest, times_list[this_machine]); //更改最长时间
    }
    for (int i = 0; i < machine_num; ++i) {
        cout << "编号" << i << "机器总时长：" << times_list[i] << endl;
        cout << "  所有任务各自时长：";
        for (double task : dispatch_list[i]) {
            cout << task << " ";
        }
        cout << endl;
    }
}

#endif //SORT_DISPATCH_H
