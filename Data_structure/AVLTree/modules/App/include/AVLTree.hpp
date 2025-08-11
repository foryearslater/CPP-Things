/**
 * @file AVLTree.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  平衡二叉树(AVL)模板类实现
 * @version 0.1
 * @date 2025-07-18
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include <iostream>
#include <stack>

template<class K, class V>
struct AVLTreeNode
{
    K key;
    V value;
    int balance;

    AVLTreeNode<K, V>* parent;
    AVLTreeNode<K,V> *left;
    AVLTreeNode<K,V> *right;

    AVLTreeNode(const K& key, const V& value = 1): 
        key(key), 
        value(value),
		balance(0),
		parent(nullptr),
        left(nullptr), 
        right(nullptr)
    {}
} ;

template<class K, class V>
class AVLTree
{
    using Node = AVLTreeNode<K, V>;
public:
    AVLTree():root(nullptr) {}

    /**
    * @brief 插入数据
    * @param key 要插入的键
    * @param value 要插入的值
    * @return bool 是否插入成功 (如果键已存在，则返回false)
    */
    bool Insert(const K& key, const V& value);

    /**
    * @brief 非递归查找数据
    * @param key 要查找的键
    * @return Node* 找到的节点指针，未找到返回nullptr
    */
    Node* Find(const K& key);


    /**
     * @brief 非递归删除数据。
     * @param key 要删除的键
     * @return bool 是否删除成功
     */
    bool Remove(const K& key);

public:

    /**
    * @brief 获取树中最小键值的节点
    * @return Node* 指向最小键值节点的指针，空树时返回nullptr
    */
	Node* Min();

    /**
    * @brief 获取树中最大键值的节点
    * @return Node* 指向最大键值节点的指针，空树时返回nullptr
    */
    Node* Max();

    /**
    * @brief 中序遍历
    */
    void Inorder();

    /**
    * @brief 先序遍历
    */
    void Preorder();

    /**
    * @brief 后序遍历
    */
    void Postorder();

    /**
    * @brief 计算树的高度
    * @return int 树的高度（空树为-1，单个节点为0）
    */

    int Height();

    /**
    * @brief 检查树是否是有效的AVL树
    * @return bool 平衡返回true，否则false
    */
    bool IsBalanced();

public:

    Node* root;

private:

    /**
    * @brief 对节点p进行左旋
    *
    *       p                       c
    *      / \                     / \
    *     T1  c         ==>       p   T3
    *        / \                 / \
    *       T2  T3              T1  T2
    *
    * @param p 需要旋转的节点 (失衡点)
    * @return Node* 旋转后子树的新根节点 (c)
    */
    Node* Rotate_L(Node* p);

    /**
    * @brief 对节点p进行右旋
    *
    *         p                     c
    *        / \                   / \
    *       c   T3     ==>        T1  p
    *      / \                       / \
    *     T1  T2                    T2  T3
    *
    * @param p 需要旋转的节点 (失衡点)
    * @return Node* 旋转后子树的新根节点 (c)
    */
    Node* Rotate_R(Node* p);

    /**
    * @brief 右-左双旋转 (先对p->right右旋，再对p左旋)
    * @param p 失衡点
    * @return Node* 旋转后子树的新根节点
    */

    Node* Rotate_RL(Node* p);

    /**
     * @brief 左-右双旋转 (先对p->left左旋，再对p右旋)
     * @param p 失衡点
     * @return Node* 旋转后子树的新根节点
     */

    Node* Rotate_LR(Node* p);

    /**
    * @brief 插入后从指定节点向上回溯，更新平衡因子并进行旋转
    * @param parent 插入节点的父节点
    * @param insertedNode 新插入的节点
    */
    void Rebalance_After_Insert(Node* parent, Node* insertedNode);

    /**
    * @brief 删除后从指定节点向上回溯，更新平衡因子并进行旋转
    * @param current 需要开始回溯调整的节点
    */

    void Rebalance_After_Remove(Node* cur);

    /**
    * @brief 对失衡节点执行正确的旋转操作
    * @param p 失衡的节点
    * @return Node* 旋转后子树的新根节点
    */

    Node* Rebalance(Node* p);

    /**
    * @brief 内部函数，处理节点的物理删除，并返回回溯调整的起始点
    * @param target 要删除的节点
    * @return Node* 回溯调整的起始点 (通常是被删除节点的父节点)
    */
    Node* Remove_Node(Node* target);

    /**
     * @brief 辅助函数，更新父节点的子节点指针
     * @param parent 父节点
     * @param oldChild 旧的子节点
     * @param newChild 新的子节点
     */
    void Update_Parent_Child(Node* parent, Node* oldChild, Node* newChild);

    /**
    * @brief 递归销毁树
    * @param node 当前节点
    */
    void Destroy(Node* node);

    /**
    * @brief 递归计算节点高度
    * @param node 当前节点
    * @return int 高度
    */

    int Height(Node* node);
    
    /**
     * @brief 递归检查树是否平衡
     * @param node 当前节点
     * @return bool 是否平衡
     */
    bool Is_Balanced(Node* node);

};
