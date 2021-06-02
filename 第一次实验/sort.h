#pragma once

#ifndef _list_sort_
#define _list_sort_
#include "list.h"
#include <iostream>
using namespace std;
template <typename T>
void List<T>::sort(Node_Posi<T> p, int n)
{
	merge_sort(p, n);
}
template <typename T>
Node_Posi<T> List<T>::merge_sort(Node_Posi<T> p, int n)
{
	if (n < 2)
		return p;
	int mid = n >> 1; //取中点
	Node_Posi<T> q = p;
	for (int i = 0; i < mid; i++)
		q = q->succ;
	p = merge_sort(p, mid);
	q = merge_sort(q, n - mid);
	Node_Posi<T> temp = p;
	for (int i = 0; i < mid; i++)
		temp = temp->succ;
	//检查是否合法
	if (temp != q)
		cout << "不合法";
	return merge(p, mid, q, n - mid);
}

template <typename T>
Node_Posi<T> List<T>::merge(Node_Posi<T> p, int n, Node_Posi<T> q, int m)
{
	//assert p, q在同一个list中，两端列表紧邻，并且p在前
	//并且两端都是有序的
	Node_Posi<T> result;
	if (p->data <= q->data)
		result = p;
	else
		result = q;
	while (n > 0 && m > 0)
	{
		if (p->data <= q->data)
		{
			p = p->succ;
			n--;
		} //如果p的data小，则将p指针后移
		else
		{
			q = q->move_ahead_of(p);
			m--;
		}
	}
	return result;
}

template <typename T>
int List<T>::ordered()
{
	int result = 0;
	Node_Posi<T> p = first();
	for (int i = 0; i < _size - 1; i++)
	{
		result += int(p->data > p->succ->data);
		p = p->succ;
	}
	return result;
}
#endif

template <typename T>
Node_Posi<T> List<T>::insert_ordered(T const &e)
{
	Node_Posi<T> p = search(e);
	++_size;
	return p->Insert_as_pred(e);
}