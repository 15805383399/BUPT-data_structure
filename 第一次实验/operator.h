#pragma once


#ifndef _list_operator_
#define _list_operator_
#include "list.h"
template<typename T>
inline Node_Posi<T> List<T>::operator[](Rank i)
{
	Node_Posi<T> p = first();
	while (i--) p = p->succ;

	return p;
}
#endif // !_list_operator_
