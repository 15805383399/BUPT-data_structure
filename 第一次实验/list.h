/*
 * @����: 
 * @�汾: 
 * @����: ���ȿ�
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
	// �������������������ֱ����������б�
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
	void init();									//����ͬ�Ĺ��캯�����ã����г�ʼ��
													//������нڵ㲢��������֮ǰ���б���
	void copy_Nodes(List<T> const &list, int n);	//�����б��ͬ��ʼ��ǰn��Ԫ��
	void copy_Nodes(Node_Posi<T> p, int n);			//���ƴӽڵ�p��ʼ��n��Ԫ��
	Node_Posi<T> merge_sort(Node_Posi<T> p, int n); //�ڲ��鲢������Ϊ����ȫ���Ϸ�
	Node_Posi<T> merge(Node_Posi<T> p, int n, Node_Posi<T> q, int m);

public:
	List() { init(); }											//Ĭ�ϳ�ʼ�����б�
	List(List<T> const &list) { copy_Nodes(list, list._size); } //���������б�
	List(List<T> const &list, int n) { copy_Nodes(list, n); }	// ����ǰn��Ԫ��
	List(List<T> const &list, Rank r, int n);					//���ƴ�r��ʼ��n��Ԫ��
	List(Node_Posi<T> p, int n) { copy_Nodes(p, n); }			//���ƴӽڵ�p��ʼ��n��Ԫ��
	List(List<T> &list1, List<T> &list2);						//�鲢������������Ϊ������
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

	void sort(Node_Posi<T> p, int n);	  // ��������
	void sort() { sort(first(), _size); } //��������
	int ordered();						  //����������

	Node_Posi<T> search(T const &e); //�������� ���ص�һ�����ڵ��� e�� �ڵ�
	Node_Posi<T> insert_ordered(T const &e);
	void append(List<T> &list); //��ȸ���

	Node_Posi<T> operator[](Rank i);

	void print();
};

#include "list_impletation.h"
#endif // !_List_H
