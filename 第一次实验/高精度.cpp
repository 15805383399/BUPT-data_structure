/*
 * @����: 
 * @�汾: 
 * @����: ���ȿ�
 * @Date: 2021-04-10 14:54:49
 * @LastEditTime: 2021-05-10 23:26:56
 */
using namespace std;
#include "list.h"
#include <iostream>
#include <ctime>

List<int> list_plus(List<int> &a, List<int> &b)
// ʵ�����������ʾ�Ĵ������
{
    List<int> result;
    int m = a.size(), n = b.size();
    Node<int> *a_p = a.last();
    Node<int> *b_p = b.last();
    int carry = 0;
    while (m > 0 && n > 0)
    {
        --m;
        --n;
        int temp = a_p->data + b_p->data + carry;
        carry = temp / 10;
        result.Insert_as_first(temp % 10);
        a_p = a_p->pred;
        b_p = b_p->pred;
    }
    while (m > 0)
    {
        --m;
        int temp = a_p->data + carry;
        carry = temp / 10;
        result.Insert_as_first(temp % 10);
        a_p = a_p->pred;
    }
    while (n > 0)
    {
        --n;
        int temp = b_p->data + carry;
        carry = temp / 10;
        result.Insert_as_first(temp % 10);
        b_p = b_p->pred;
    }
    if (carry != 0)
    {
        result.Insert_as_first(carry);
    }
    return result;
}

bool larger(List<int> &a, List<int> &b)
// �ж����������ʾ�Ĵ�������һ���Ƿ�С�ڵڶ���
{
    if (a.size() > b.size())
        return true;
    else if (a.size() < b.size())
        return false;
    else // a.size() == b.size()
    {
        Node<int> *a_p = a.first();
        Node<int> *b_p = b.first();
        for (int i = 0; i < a.size(); i++)
        {
            if (a_p->data > b_p->data)
                return true;
            else if (a_p->data < b_p->data)
                return false;
            a_p = a_p->succ;
            b_p = b_p->succ;
        }
        return true; //��ȫ���
    }
}

List<int> _list_minus(List<int> &a, List<int> &b)
{
    // ��֤�����a >= b
    List<int> result;
    int m = a.size(), n = b.size();
    Node<int> *a_p = a.last();
    Node<int> *b_p = b.last();
    int carry = 0;
    while (m > 0 && n > 0)
    {
        --m;
        --n;
        int temp = a_p->data - b_p->data - carry;
        result.Insert_as_first(temp);
        a_p = a_p->pred;
        b_p = b_p->pred;
        if (temp < 0)
        {
            carry = 1;
            temp += 10;
        }
        else
            carry = 0;
    }
    while (m-- > 0)
    {
        result.Insert_as_first(a_p->data);
        a_p = a_p->pred;
        carry = 0;
    }
    return result;
}

List<int> list_minus(List<int> &a, List<int> &b)
// ʵ�����������ʾ�Ĵ��������
{
    if (larger(a, b))
        return _list_minus(a, b);
    else
    {
        List<int> result = _list_minus(b, a);
        result.first()->data *= -1;
        return result;
    }
}

List<int> get_random_num(int n) //n Ϊ���������λ��
{
    int size = rand() % n + 1; //ȡ��������ִ���λ��
    List<int> result;
    for (int i = 0; i < size - 1; i++)
        result.Insert_as_first(rand() % 10);
    result.Insert_as_first(rand() % 9 + 1); //��һ����������0
    return result;
}

void show_result(List<int> a, List<int> b, List<int> result)
{
    int size = result.size();
    int m = a.size();
    int n = b.size();
    for (int i = 0; i < size - m; i++)
    {
        a.Insert_as_first(0);
    }
    for (int i = 0; i < size - n; i++)
    {
        b.Insert_as_first(0);
    }
    cout << "��һ����:";
    a.print();
    cout << "�ڶ�����:";
    b.print();
    cout << "���:    ";
    result.print();
}

int main()
{
    srand(time(NULL));
    // ȡ���Ķ���������
    List<int> num1 = get_random_num(10);
    List<int> num2 = get_random_num(20);

    List<int> result = list_plus(num1, num2);
    show_result(num1, num2, result);

    list_minus(num1, num2).print();
    return 0;
}