/*
 * @ÃèÊö: 
 * @°æ±¾: 
 * @×÷Õß: ÁÎŞÈ¿­
 * @Date: 2021-05-10 22:50:01
 * @LastEditTime: 2021-05-12 13:12:04
 */

#include "list.h"

template <typename T>
class ChainStack
{
private:
    List<T> data;

public:
    ChainStack() {}
    ~ChainStack() { empty(); }
    void push(T &e) { data.Insert_as_last(e); }
    T top() { return data.last()->data; }
    T pop() { return data.remove(data.last()); }
    int clear() { return data.clear(); }
    bool empty() { return data.size() > 0; }
    void print() { data.print(); }
};