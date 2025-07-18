/**
 * @file RBTree.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  红黑树模板类实现
 * @version 0.1
 * @date 2025-07-18
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include <iostream>
#include <stack>

enum Color
{
    RED,  
    BLACK 
};

template<class K, class V>
struct RBTreeNode
{
    K key;
    V value;
    Color color;
    RBTreeNode<K,V> *left;
    RBTreeNode<K,V> *right;
    RBTreeNode<K, V>*parent;

    RBTreeNode(const K& key = K(), const V& value = V())
        : key(key)
        , value(value)
        , color(RED)
        , left(nullptr)
        , right(nullptr)
        , parent(nullptr)
    {}
} ;

/**
 * @brief 红黑树模板类
 *
 * 红黑树是一种自平衡的二叉查找树，它满足以下五条性质：
 * 1. 每个节点要么是红色，要么是黑色。
 * 2. 根节点是黑色的。
 * 3. 每个叶子节点（NIL 或 nullptr）是黑色的。
 * 4. 如果一个节点是红色的，则它的两个子节点都是黑色的（不能有两个连续的红色节点）。
 * 5. 从任一节点到其每个叶子节点的所有路径都包含相同数目的黑色节点（黑高）。
 */

template<class K, class V>
class RBTree
{
    typedef RBTreeNode<K, V> Node;
public:
    RBTree(): root(nullptr){}

    /**
     * @brief 向红黑树中插入一个键值对
     * @param key   要插入的键
     * @param value 要插入的值
     * @return bool 如果键不存在，则插入成功返回true；否则返回false。
     */
    bool Insert(const K& key, const V& value);

    /**
     * @brief 中序遍历红黑树并打印键值
     */
    void InOrder();

    /**
     * @brief 检查当前树是否满足红黑树的所有性质
     * @return bool 如果满足，返回true；否则返回false并打印错误信息。
     */
    bool Check();

protected:

    /**
     * @brief 对指定节点进行左旋操作
     * @param parent 待旋转子树的根节点（引用传递，旋转后会更新为新的子树根）
     *
     *        |                       |
     *        p (parent)              sR
     *       / \                     / \
     *      pL  sR       ==>        p   sRR
     *         / \                 / \
     *       sRL  sRR             pL  sRL
     */
    void Rotate_L(Node*& parent);

    /**
     * @brief 对指定节点进行右旋操作
     * @param parent 待旋转子树的根节点（引用传递，旋转后会更新为新的子树根）
     *
     *        |                       |
     *        p (parent)              sL
     *       / \                     /  \
     *      sL  pR       ==>       sLL   p
     *     / \                         / \
     *   sLL  sLR                     sLR pR
     */
    void Rotate_R(Node*& parent);

    /**
    * @brief 中序遍历红黑树并打印键值
    */
    void InOrder(Node* root);

    /**
    * @brief 递归检查红黑树的合法性
    */
    bool Check(Node* root, int blackNum, int currentBlackNum);

protected:

    Node* root; 

};