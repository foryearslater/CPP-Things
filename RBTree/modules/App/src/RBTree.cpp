/**
 * @file RBTree.cpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  红黑树模板类实现
 * @version 0.1
 * @date 2025-07-21
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "RBTree.hpp"

template<class K, class V>
bool RBTree<K, V>::Insert(const K & key, const V & value)
{
    if (root == nullptr)
    {
        root = new Node(key, value);
        root->color = BLACK;
        return true;
    }
    Node* cur = root;
    Node* parent =  nullptr;
    while(cur)
    {
        parent = cur;
        if (key < cur->key)
        {
            cur = cur->left;
        }
        else if (key > cur->key)
        {
            cur = cur->right;
        }
        else 
        {
            return false;
        }
    }
    cur = new Node(key, value);
    cur->parent = parent;
    if (key < parent->key)
    {
        parent->left = cur;
    }
    else
    {
        parent->right = cur;
    }

    while (cur != root && parent->color == RED)
    {
        Node* grandparent = parent->parent;
        if (parent == grandparent->left)
        {
            Node* uncle = grandparent->right;
            if (uncle && uncle->color == RED)
            {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                cur = grandparent;
                parent = cur->parent; 
            }
            else
            {

                if (cur == parent->right)
                {
                    cur = parent;
                    Rotate_L(cur); 
                    parent = cur->parent;
                }
                parent->color = BLACK;
                grandparent->color = RED;
                Rotate_R(grandparent);
                break;
            }
        }
        else
        {
            Node* uncle = grandparent->left;
            if (uncle && uncle->color == RED)
            {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                cur = grandparent;
                parent = cur->parent;
            }
            else
            {
                if (cur == parent->left)
                {
                    cur = parent;
                    Rotate_R(cur);
                    parent = cur->parent;
                }
                parent->color = BLACK;
                grandparent->color = RED;
                Rotate_L(grandparent);
                break;
            }
        }
    }
    
    root->color = BLACK;
    return true;
}
template<class K, class V>
void RBTree<K,V>::Rotate_L(Node*& p)
{
    Node* subR = p->right;
    Node* pParent = p->parent;

    p->right = subR->left;
    if (subR->left)
    {
        subR->left->parent = p;
    }

    subR->parent = pParent;
    if (pParent == nullptr) 
    {
        root = subR;
    }
    else if (p == pParent->left)
    {
        pParent->left = subR;
    }
    else
    {
        pParent->right = subR;
    }

    subR->left = p;
    p->parent = subR;
    
    p = subR;
}

template<class K, class V>
void RBTree<K,V>::Rotate_R(Node*& p)
{
    Node* subL = p->left;
    Node* pParent = p->parent;

    p->left = subL->right;
    if (subL->right)
    {
        subL->right->parent = p;
    }

    subL->parent = pParent;
    if (pParent == nullptr) 
    {
        root = subL;
    }
    else if (p == pParent->right)
    {
        pParent->right = subL;
    }
    else
    {
        pParent->left = subL;
    }

    subL->right = p;
    p->parent = subL;
    
    p = subL;
}

template<class K, class V>
void RBTree<K,V>::InOrder()
{
    std::cout << "--- In-Order Traversal ---" << std::endl;
    InOrder(root);
    std::cout << "--------------------------" << std::endl;
}

template<class K, class V>
void RBTree<K,V>::InOrder(Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    InOrder(node->left);
    std::cout << node->key << ":" << node->value << " (" << (node->color == RED ? "RED" : "BLACK") << ")" << std::endl;
    InOrder(node->right);
}

template<class K, class V>
bool RBTree<K,V>::Check()
{
    if (root == nullptr)
    {
        return true; 
    }

    if (root->color != BLACK)
    {
        std::cout << "Violation: Root is not BLACK." << std::endl;
        return false;
    }

    int blackNum = 0;
    Node* cur = root;
    while(cur)
    {
        if (cur->color == BLACK)
        {
            blackNum++;
        }
        cur = cur->left;
    }

    return Check(root, blackNum, 0);
}

template<class K, class V>
bool RBTree<K,V>::Check(Node* node, int blackNum, int currentBlackNum)
{
    if (node == nullptr)
    {
        if (currentBlackNum != blackNum)
        {
            std::cout << "Violation: Black height mismatch. Expected "
                      << blackNum << ", but got " << currentBlackNum << " on one path." << std::endl;
            return false;
        }
        return true;
    }
    if (node->color == RED)
    {
        if ((node->left && node->left->color == RED) || (node->right && node->right->color == RED))
        {
             std::cout << "Violation: Red node " << node->key << " has a red child." << std::endl;
             return false;
        }
    }
    
    if (node->color == BLACK)
    {
        currentBlackNum++;
    }

    return Check(node->left, blackNum, currentBlackNum) &&
           Check(node->right, blackNum, currentBlackNum);
}
template class RBTree<int, std::string> ;
