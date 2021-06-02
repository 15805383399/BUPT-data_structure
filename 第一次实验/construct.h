
#ifndef _construct_

#define _construct_

#include "list.h"

template <typename T>
void List<T>::init()
{
	header = new Node<T>;  //ͷ���
	trailor = new Node<T>; //β�ڵ�
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
	//����ɾ����һ��node��ֱ�����
	while (_size > 0)
	{
		remove(header->succ);
	}
	return old_size;
}

template <typename T>
void List<T>::copy_Nodes(List<T> const &list, int n)
{
	//�ж�n�Ƿ�Ϸ�����֤���ʰ�ȫ
	init();
	if (n > list._size)
		n = list._size;
	_size = n;
	Node_Posi<T> p = list.header->succ;
	// β�巨
	for (int i = 0; i < n; i++)
	{
		trailor->Insert_as_pred(p->data);
		p = p->succ;
	}
}
template <typename T>
void List<T>::copy_Nodes(Node_Posi<T> p, int n)
{
	init(); //�Ƚ��г�ʼ��
	// ��Ϊ���ⲿ�޷�����header����trailor�ڵ㣬����ֻҪp != NULL ���ǰ�ȫ��
	if (p != NULL)
	{
		while (p->succ != NULL && n--)
		{
			Insert_as_last(p->data); //��insert�а�����_size++
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
		// r+n-1 ��ʾ�����ʵ������һ��Ԫ�أ�����Խ��
		// ���Խ�磬��Сn����ֵ����n��СΪ 1
		if (r + n - 1 > list._size)
			n = list._size - r + 1;
		Node_Posi<T> p = list.first();
		while (r-- > 0)
			p = p->succ;			 //Ѱ�ȷ��ʵ�r�ڵ�
		while (n-- > 0)				 //�Ѿ��жϹ��ǰ�ȫ�ģ����������ж�p�Ƿ�ΪNULL
			Insert_as_last(p->data); //��insert�а�����_size++
	}
}
template <typename T>
List<T>::List(int n, T const &e)
{
	init();
	if (n > 0)
	{ //�ж�n�����Ƿ�Ϸ�
		_size = n;
		// ͷ�巨
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
void List<T>::append(List<T> &list) //���б���ȿ�������ǰ�б��β��
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
