/*
 * @描述: 
 * @版本: 
 * @作者: 廖奕凯
 * @Date: 2021-04-01 14:29:22
 * @LastEditTime: 2021-05-12 13:12:43
 */
#pragma once

#include "node.h"
#include <iostream>
#ifndef _List_H
#define _List_H
template <typename T>
class List
{
	// 重载输出控制流，可以直接输出整个列表
	friend ostream &operator<<(ostream &out, List<T> &list)
	{
		Node_Posi<T> p = list.first();
		int n = list.size();
		while (n--)
		{
			out << p << " ";
			p = p->succ;
		}
		return out;
	}

private:
	int _size;
	Node_Posi<T> header;
	Node_Posi<T> trailor;

protected:
	void init();									//供不同的构造函数调用，进行初始化
													//清楚所有节点并，并返回之前的列表长度
	void copy_Nodes(List<T> const &list, int n);	//复制列表从同开始的前n项元素
	void copy_Nodes(Node_Posi<T> p, int n);			//复制从节点p开始的n个元素
	Node_Posi<T> merge_sort(Node_Posi<T> p, int n); //内部归并排序，认为参数全部合法
	Node_Posi<T> merge(Node_Posi<T> p, int n, Node_Posi<T> q, int m);

public:
	List() { init(); }											//默认初始化空列表
	List(List<T> const &list) { copy_Nodes(list, list._size); } //复制整个列表
	List(List<T> const &list, int n) { copy_Nodes(list, n); }	// 复制前n个元素
	List(List<T> const &list, Rank r, int n);					//复制从r开始的n个元素
	List(Node_Posi<T> p, int n) { copy_Nodes(p, n); }			//复制从节点p开始的n个元素
	List(List<T> &list1, List<T> &list2);						//归并两个有序链表为新链表
	List(int n, T const &e);
	~List();
	T remove(Node_Posi<T> p);
	int clear();
	Node_Posi<T> first() { return header->succ; }
	Node_Posi<T> last() { return trailor->pred; }
	Node_Posi<T> Insert_as_first(T const &e)
	{
		_size++;
		return header->Insert_as_succ(e);
	}
	Node_Posi<T> Insert_as_last(T const &e)
	{
		_size++;
		return trailor->Insert_as_pred(e);
	}
	int size() { return _size; }

	void sort(Node_Posi<T> p, int n);	  // 区间排序
	void sort() { sort(first(), _size); } //整体排序
	int ordered();						  //返回逆序数

	Node_Posi<T> search(T const &e); //有序链表 返回第一个大于等于 e的 节点
	Node_Posi<T> insert_ordered(T const &e);
	void append(List<T> &list); //深度复制

	Node_Posi<T> operator[](Rank i);

	void print();
};

#include "list_impletation.h"
#endif // !_List_H
