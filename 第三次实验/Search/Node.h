//
// Created by lyk on 2021/6/5.
//

#ifndef SEARCH_NODE_H
#define SEARCH_NODE_H
template<typename T>
struct Node {
    T data;
    Node<T> *left, *right;
    Node() : key(0), left(NULL), right(NULL){};
    Node(T k) :key(k) , left(NULL), right(NULL){};
};
#endif //SEARCH_NODE_H
