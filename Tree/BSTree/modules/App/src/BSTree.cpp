#include "BSTree.hpp"

template<class K, class V>
bool BSTree<K, V>::Insert(const K& key, const V& value)
{
    if (root == nullptr)
    {
        root = new BSTNode<K, V>(key, value);
        return true;
    }
    BSTNode<K, V>* cur = root;
    BSTNode<K, V>* parent = root;
    while (cur)
    {
        parent = cur;
        if (cur->key < key)
        {
            cur = cur->right;
        }
        else if (cur->key > key)
        {
            cur = cur->left;
        }
        else 
        {
            cur->value = value;
            return false;
        }
    }
    if (key > parent->key)
    {
        parent->right = new BSTNode<K, V>(key, value);
    }
    else 
    {
        parent->left  = new BSTNode<K, V>(key, value);
    }
    return true;
}
template<class K, class V>
bool BSTree<K, V>::Insert_R(BSTNode<K, V>*& root, const K& key, const V& value)
{
    if (root == nullptr)
    {
        root == new BSTNode<K, V>(key, value);
        return true;
    }
    else if (root->key < key)
    {
        return Insert_R(root->right, key, value);
    }
    else if (root->key > key)
    {
        return Insert_R(root->left, key, value);
    }
    else 
    {
        return false;
    }
}
template<class K, class V>
BSTNode<K, V>* BSTree<K, V>::Find(const K& key)
{
    if (root == nullptr) 
    {
        return nullptr;
    }
    BSTNode<K, V>* cur = root;
    while (cur)
    {
        if (cur->key == key)
        {
            return cur;
        }
        else if (cur->key > key)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    return nullptr;
}
template<class K, class V>
BSTNode<K, V>* BSTree<K, V>::Find_R(BSTNode<K, V>*& root, const K& key)
{
    if (root == nullptr) 
    {
        return nullptr;
    }
    BSTNode<K, V>* cur = root;
    if (cur->key == key)
    {
        return cur;
    }
    else if (cur->key > key)
    {
        return Find_R(root->left, key);
    }
    else
    {
        return Find_R(root->right, key);
    }
    return nullptr;
}
template<class K, class V>
bool BSTree<K, V>::Remove(const K& key)
{
	BSTNode<K, V>* parent = nullptr;
    BSTNode<K, V>* cur = root;
    while (cur != nullptr)
    {
        if (cur->key < key)
        {
            parent = cur;
            cur = cur->right;
        }
        else if (cur->key > key)
        {
            parent = cur;
            cur = cur->left;
        }
        else 
        {
            break;
        }
    }
    if (cur == nullptr)
    {
        return false;
    }

    if (cur->left == nullptr || cur->right == nullptr)
    {
        BSTNode<K, V>* child = cur->left ? cur->left : cur->right;

        if (parent == nullptr)
        {
            root = child;
        }
        else
        {
            if (parent->left == cur)
            {
                parent->left = child;
            }
            else 
            {
                parent->right = child;
            }
        }
        delete cur;
    }
    else
    {
        BSTNode<K, V>* sucessor_parent = cur;
        BSTNode<K, V>* sucessor = cur->right;

        while (sucessor->left != nullptr)
        {
            sucessor_parent = sucessor;
            sucessor = sucessor->left;
        }
        cur->key = sucessor->key;
        cur->value = sucessor->value;

        if(sucessor_parent->left == sucessor)
        {
            sucessor_parent->left = sucessor->right;
        }
        else
        {
            sucessor_parent->right = sucessor->right;
        }
        delete sucessor;
    }
    return true;
}
template<class K, class V>
bool BSTree<K, V>::Remove_R(BSTNode<K, V>*& root, const K& key)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->key > key)
    {
        return Remove_R(root->left, key);
    }
    else if(root->key < key)
    {
        return Remove_R(root->right, key);
    }
    BSTNode<K, V>* toDelete = root;
    if (!root->left || !root->right) 
    {
        root = (root->left) ? root->left : root->right;
        delete toDelete;
        return true;
    }

    BSTNode<K, V>* min_right = root->right;
    while (min_right->left) {
        min_right = min_right->left;
    }
    
    root->key = min_right->key;
    root->value = min_right->value;

    return Remove_R(root->right, min_right->key);
}
template<class K, class V>
BSTNode<K, V>* BSTree<K, V>::Min()
{
    if (root == nullptr) 
    {
        return nullptr;
    }
    BSTNode<K, V>* cur = root;
    while (cur->left != nullptr)
    {
        cur = cur->left;
    }
    return cur;
}
template<class K, class V>
BSTNode<K, V>* BSTree<K, V>::Max()
{
    if (root == nullptr) 
    {
        return nullptr;
    }
    BSTNode<K, V>* cur = root;
    while (cur->right != nullptr)
    {
        cur = cur->right;
    }
	return cur;
}
template<class K, class V>
int BSTree<K, V>::Height(BSTNode<K, V>*& root)
{
    if (root == nullptr) 
    {
        return -1;
    }
    int left_height = Height(root->left);
    int right_height = Height(root->right);
    return std::max(left_height, right_height) + 1;
}
template<class K, class V>
void BSTree<K, V>::Preorder()
{
    if (root == nullptr) 
    {
        return;
    }
    std::stack<BSTNode<K, V>*> stack;
    stack.push(root);
    while (!stack.empty())
    {
        BSTNode<K, V>* node = stack.top();
        stack.pop();
        std::cout << node->key << " ";
        if (node->right != nullptr)
        {
            stack.push(node->right);
        }
        if (node->left != nullptr)
        {
            stack.push(node->left);
        }
	}
    std::cout << "\n";
}
template<class K, class V>
void BSTree<K, V>::Inorder()
{
    if (this->root == nullptr) 
    {
        return;
    }
    std::stack<BSTNode<K, V>*> stack;
    BSTNode<K, V>* cur = this->root;
    while (cur != nullptr || !stack.empty())
    {
        while (cur != nullptr)
        {
            stack.push(cur);
            cur = cur->left;
        }
        cur = stack.top();
        stack.pop();
        std::cout << cur->key << " ";
        cur = cur->right;
	}
    std::cout << "\n";
}
template<class K, class V>
void BSTree<K, V>::Postorder()
{
    if (!root) return;

    std::stack<BSTNode<K, V>*> stack;
    std::stack<BSTNode<K, V>*> output;
    stack.push(root);

    while (!stack.empty()) 
    {
        BSTNode<K, V>* current = stack.top();
        stack.pop();
        output.push(current);

        if (current->left)  stack.push(current->left);
        if (current->right) stack.push(current->right);
    }

    while (!output.empty()) 
    {
        std::cout << output.top()->key << " ";
        output.pop();
    }
    std::cout << "\n";
}
template<class K, class V>
bool BSTree<K, V>::IsBalanced()
{
    auto check = [](auto&& self, BSTNode<K, V>* node) -> std::pair<bool, int> 
    {
        if (nullptr == node)
        {
            return { true, -1 };
        }

        auto [left_balanced, left_height]   =   self(self, node->left);
        auto [right_balanced, right_height] =   self(self, node->right);

        int current_height = 1 + std::max(left_height, right_height);
        int balance = std::abs(left_height - right_height);
        bool balanced = left_balanced && right_balanced && (balance <= 1);

        return { balanced, current_height };
    };

    auto [balanced, _] = check(check, root);
    return balanced;
}
template class BSTree<int, int>;