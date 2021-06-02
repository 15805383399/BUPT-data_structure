#pragma once

#ifndef _search_h_
#define _search_h_
#include "list.h"
template <typename T>
Node_Posi<T> List<T>::search(T const &e)
{
	Node_Posi<T> iter = first();
	int n = _size;
	while (iter->data < e && n-- > 0)
	{
		iter = iter->succ;
	}
	return iter;
}

#endif // !_search_h_
