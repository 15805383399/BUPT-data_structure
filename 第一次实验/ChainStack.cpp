/*
 * @描述: 
 * @版本: 
 * @作者: 廖奕凯
 * @Date: 2021-05-10 22:53:23
 * @LastEditTime: 2021-05-12 13:10:52
 */
#include "ChainStack.h"

int main()
{
    ChainStack<int> a;
    for (int i = 0; i < 10; i++)
    {
        a.push(i);
    }
    a.print();
    cout << "pop\t" << a.pop() << endl;
    cout << "top\t" << a.top() << endl;
    a.clear();
    return 0;
}