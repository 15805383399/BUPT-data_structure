/*
 * @����: 
 * @�汾: 
 * @����: ���ȿ�
 * @Date: 2021-04-01 21:29:21
 * @LastEditTime: 2021-04-07 14:50:44
 */
#pragma once
#include <iostream>
using namespace std;
#ifndef _Node_H_
#define _Node_H_
using Rank = int;
template <typename T>
struct Node;
template <typename T>
using Node_Posi = Node<T> *; //�ڵ�ָ��
template <typename T>
struct Node
{
	T data;
	Node_Posi<T> pred, succ;
	Node() {}										//���header trailor ���캯��
	Node(T element, Node_Posi<T> p, Node_Posi<T> s) // Ĭ�Ϲ��캯��
		: data(element), pred(p), succ(s)
	{
	}

	Node_Posi<T> Insert_as_pred(T const &e);
	Node_Posi<T> Insert_as_succ(T const &e);
	Node_Posi<T> move_ahead_of(Node_Posi<T> p);

	friend ostream &operator<<(ostream &os, Node<T> &node) { return os << node.data; }
	friend ostream &operator<<(ostream &os, Node_Posi<T> p) { return os << p->data; }
};

#include "node_insert.h"
#endif // !_Node_H_
