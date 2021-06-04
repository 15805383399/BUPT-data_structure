#include "utils.h"
#include "bubble_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "bucket_sort.h"
#include "heap_sort.h"

template<typename T> int Sort<T>::count_move = 0;
template<typename T> int Sort<T>::count_compare = 0;

