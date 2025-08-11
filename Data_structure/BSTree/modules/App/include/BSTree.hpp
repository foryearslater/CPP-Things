/**
 * @file BSTree.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  二叉搜索树(BST)模板类实现
 * @version 0.1
 * @date 2025-07-17
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include <iostream>
#include <stack>

template<class K, class V>
struct BSTNode
{
    K key;
    V value;
    BSTNode<K,V> *left;
    BSTNode<K,V> *right;
    BSTNode(const K& key, const V& value = 1): key(key), value(value), left(nullptr), right(nullptr){}
} ;

template<class K, class V>
class BSTree
{
public:
    BSTree():root(nullptr) {}

     /**
     * @brief 递归插入数据
     * @param key 要插入的键
     * @param value 要插入的值
     * @return bool 是否插入成功
     */
    bool Insert_R(BSTNode<K, V>*& root, const K& key, const V& value);

    /**
     * @brief 递归查找数据
     * @param key 要查找的键
     * @return BSTNode<K, V>* 找到的节点指针，未找到返回nullptr
     */
    BSTNode<K, V>* Find_R(BSTNode<K, V>*& root, const K& key);

     /**
     * @brief 递归删除数据
     * @param key 要删除的键
     * @return bool 是否删除成功
     */

    bool Remove_R(BSTNode<K, V>*& root, const K& key);

     /**
     * @brief 非递归插入数据
     * @param key 要插入的键
     * @param value 要插入的值
     * @return bool 是否插入成功
     */

    bool Insert(const K& key, const V& value);

    /**
     * @brief 非递归查找数据
     * @param key 要查找的键
     * @return BSTNode<K, V>* 找到的节点指针，未找到返回nullptr
     */

    BSTNode<K, V>* Find(const K& key);

    /**
     * @brief 非递归删除数据
     * @param key 要删除的键
     * @return bool 是否删除成功
     */
    bool Remove(const K& key);

public:
    /**
     * @brief 获取树中最小键值的节点
     * 
     * @return BSTNode<K, V>* 指向最小键值节点的指针，空树时返回nullptr
     */
    BSTNode<K, V>* Min();     

     /**
     * @brief 获取树中最大键值的节点
     * 
     * @return BSTNode<K, V>* 指向最大键值节点的指针，空树时返回nullptr
     */

    BSTNode<K, V>* Max();     

    /**
     * @brief 中序遍历（非递归实现）
     */

    void Inorder();    

    /**
     * @brief 先序遍历（非递归实现）
     */   

    void Preorder();    

    /**
     * @brief 后序遍历（非递归实现）
     */ 

    void Postorder();

    /**
     * @brief 计算树的高度
     * 
     * @return int 树的最大深度（空树高度为-1，单个节点树高度为0）
     */

    int  Height(BSTNode<K, V>*& root);

    /**
     * @brief 检查树是否平衡（AVL树标准）
     * 
     * @return bool 平衡返回true，否则false
     */

    bool IsBalanced();   
public:

    BSTNode<K, V>* root;

};
