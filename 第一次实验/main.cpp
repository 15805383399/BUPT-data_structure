/*
 * @????: 
 * @��???: 
 * @����??: ??????
 * @Date: 2021-04-01 16:06:58
 * @LastEditTime: 2021-05-12 13:26:03
 */

#include "list.h"
#include <iostream>
#include "node.h"
using namespace std;
//�������Ա���
int main()
{
	int n = 10;
	List<int> l(n, 20);
	Node_Posi<int> p = l.first();
	for (int i = 0; i < n; i++)
	{
		p->data = n - i;
		p = p->succ;
	}
	l.print();
	cout << l.ordered() << endl;
	l.sort();
	cout << l << endl;
	cout << l.ordered() << endl;
	cout << l.insert_ordered(99) << endl;
	l.print();
	List<int> list2(n, 5);	   // ����һ������Ϊn Ԫ��ȫ��Ϊ5������
	List<int> list3(l, list2); // �ϲ���������һ�������� list3
	list3.print();
	return 0;
}