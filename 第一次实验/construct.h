
#ifndef _construct_

#define _construct_

#include "list.h"

template <typename T>
void List<T>::init()
{
	header = new Node<T>;  //头结点
	trailor = new Node<T>; //尾节点
	header->succ = trailor;
	header->pred = NULL;
	trailor->pred = header;
	trailor->succ = NULL;
	_size = 0;
}

template <typename T>
T List<T>::remove(Node_Posi<T> p)
{
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}

template <typename T>
int List<T>::clear()
{
	int old_size = _size;
	//反复删除第一个node，直到清空
	while (_size > 0)
	{
		remove(header->succ);
	}
	return old_size;
}

template <typename T>
void List<T>::copy_Nodes(List<T> const &list, int n)
{
	//判断n是否合法，保证访问安全
	init();
	if (n > list._size)
		n = list._size;
	_size = n;
	Node_Posi<T> p = list.header->succ;
	// 尾插法
	for (int i = 0; i < n; i++)
	{
		trailor->Insert_as_pred(p->data);
		p = p->succ;
	}
}
template <typename T>
void List<T>::copy_Nodes(Node_Posi<T> p, int n)
{
	init(); //先进行初始化
	// 因为在外部无法传入header或者trailor节点，所以只要p != NULL 就是安全的
	if (p != NULL)
	{
		while (p->succ != NULL && n--)
		{
			Insert_as_last(p->data); //在insert中包含了_size++
			p = p->succ;
		}
	}
}

template <typename T>
List<T>::List(List<T> const &list, Rank r, int n)
{
	init();
	if (r <= list._size)
	{
		// r+n-1 表示被访问到的最后一个元素，不能越界
		// 如果越界，缩小n的数值，且n最小为 1
		if (r + n - 1 > list._size)
			n = list._size - r + 1;
		Node_Posi<T> p = list.first();
		while (r-- > 0)
			p = p->succ;			 //寻秩访问到r节点
		while (n-- > 0)				 //已经判断过是安全的，所以无需判断p是否为NULL
			Insert_as_last(p->data); //在insert中包含了_size++
	}
}
template <typename T>
List<T>::List(int n, T const &e)
{
	init();
	if (n > 0)
	{ //判断n输入是否合法
		_size = n;
		// 头插法
		while (n--)
			header->Insert_as_succ(e);
	}
}

template <typename T>
List<T>::List(List<T> &list1, List<T> &list2)
{
	init();
	int m = list1.size(), n = list2.size();
	append(list1);
	Node_Posi<T> p = last();
	append(list2);
	p = p->succ;
	merge(first(), m, p, n);
}

template <typename T>
List<T>::~List()
{
	clear();
	delete header;
	delete trailor;
}

template <typename T>
void List<T>::print()
{
	int i = _size;
	Node_Posi<T> p = first();
	while (i--)
	{
		cout << p << ' ';
		p = p->succ;
	}
	cout << endl;
}

template <typename T>
void List<T>::append(List<T> &list) //将列表深度拷贝到当前列表的尾部
{
	Node_Posi<T> p = list.first();
	int m = list._size;
	_size += m;
	while (m--)
	{
		trailor->Insert_as_pred(p->data);
		p = p->succ;
	}
}

#endif // !_construct_
