/*
 * @ÃèÊö: 
 * @°æ±¾: 
 * @×÷Õß: ÁÎÞÈ¿­
 * @Date: 2021-04-01 21:39:15
 * @LastEditTime: 2021-05-11 21:41:00
 */

#ifndef node_insert
#define node_insert

#include "node.h"

template <typename T>
inline Node_Posi<T> Node<T>::Insert_as_pred(T const &e)
{
	Node_Posi<T> x = new Node<T>(e, pred, this);
	pred->succ = x;
	pred = x;
	return x;
}

template <typename T>
Node_Posi<T> Node<T>::Insert_as_succ(T const &e)
{
	Node_Posi<T> x = new Node<T>(e, this, succ);
	succ->pred = x;
	succ = x;
	return x;
}
template <typename T>
Node_Posi<T> Node<T>::move_ahead_of(Node_Posi<T> p)
{
	Node_Posi<T> temp = succ;

	succ->pred = pred;
	pred->succ = succ;

	pred = p->pred;
	succ = p;

	p->pred->succ = this;
	p->pred = this;

	return temp;
}
#endif // !node_insert
