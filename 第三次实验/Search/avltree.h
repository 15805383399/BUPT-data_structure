//
// Created by lyk on 2021/6/5.
//

#ifndef SEARCH_AVLTREE_H
#define SEARCH_AVLTREE_H

#include "Node.h"

template<typename T>
class AVLTree {

private:
    Node<T> *avl_root;

    int _height(const Node<T> *root); // 求树的高度
    int _diff(const Node<T> *root); // 求平衡因子
    // 单旋转
    Node<T>* _ll_rotation(Node<T> *root); // left-left rotation
    Node<T>* _rr_rotation(Node<T> *root); // right-right rotation
    // 双旋转
    Node<T>* _lr_rotation(Node<T> *root); // left-right rotation
    Node<T>* _rl_rotation(Node<T> *root); // right-left rotation

    Node<T>* _balance(Node<T>* root);   // 调整为平衡二叉树
    Node<T>* _insert(Node<T>* root, T & value); // 插入的内部接口
public:
    bool insert(T &value);  // 插入的外部接口
};


#endif //SEARCH_AVLTREE_H
