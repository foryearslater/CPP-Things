#include "AVLTree.hpp"

template<class K, class V>
bool AVLTree<K, V>::Insert(const K& key, const V& value)
{
	if (root == nullptr)
	{
		root = new Node(key, value);
		return true;
	}

	Node* parent = nullptr;
	Node* cur = root;

	while (cur != nullptr)
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
	Node* new_node = new Node(key, value);
	new_node->parent = parent;

	if (key < parent->key)
	{
		parent->left = new_node;
	}
	else
	{
		parent->right = new_node;
	}
	Rebalance_After_Insert(parent, new_node);
	return true;
}
template<class K, class V>
AVLTreeNode<K, V>* AVLTree<K, V>::Find(const K& key)
{
	Node* cur = root;
	while (cur != nullptr)
	{
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
			return cur; 
		}
	}
	return nullptr; 
}
template<class K, class V>
bool AVLTree<K, V>::Remove(const K& key)
{
	Node* target = Find(key);

	if (target == nullptr)
	{
		return false;
	}
	Node* node_to_balance = Remove_Node(target);

	if (node_to_balance != nullptr)
	{
		Rebalance_After_Remove(node_to_balance);
	}
	return true;
}
template<class K, class V>
AVLTreeNode<K, V>* AVLTree<K, V>::Min()
{
	if (root == nullptr)
	{
		return nullptr;
	}
	Node* cur = root;
	while (cur->left != nullptr)
	{
		cur = cur->left;
	}
	return cur;
}
template<class K, class V>
AVLTreeNode<K, V>* AVLTree<K, V>::Max()
{
	if (root == nullptr)
	{
		return nullptr;
	}
	Node* cur = root;
	while (cur->right != nullptr)
	{
		cur = cur->right;
	}
	return cur;
}
template<class K, class V>
void AVLTree<K, V>::Inorder()
{
	if (root == nullptr)
	{
		return;
	}
	std::stack<Node*> s;
	Node* cur = root;
	while (cur != nullptr || !s.empty())
	{
		while (cur != nullptr)
		{
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		s.pop();
		std::cout << cur->key << " ";
		cur = cur->right;
	}
	std::cout << std::endl;
}
template<class K, class V>
void AVLTree<K, V>::Preorder()
{
	if (root == nullptr)
	{
		return;
	}
	std::stack<Node*> s;
	s.push(root);
	while (!s.empty())
	{
		Node* cur= s.top();
		s.pop();
		std::cout << cur->key << " ";
		if (cur->right)
		{
			s.push(cur->right);
		}
		if (cur->left)
		{
			s.push(cur->left);
		}
	}
	std::cout << std::endl;
}
template<class K, class V>
void AVLTree<K, V>::Postorder()
{
	if (root == nullptr)
	{
		return;
	}
	std::stack<Node*> s1, s2;
	s1.push(root);
	while (!s1.empty())
	{
		Node* cur = s1.top();
		s1.pop();
		s2.push(cur);
		if (cur->left)
		{
			s1.push(cur->left);
		}
		if (cur->right)
		{
			s1.push(cur->right);
		}
	}
	while (!s2.empty())
	{
		std::cout << s2.top()->key << " ";
		s2.pop();
	}
	std::cout << std::endl;
}

template<class K, class V>
int  AVLTree<K, V>::Height()
{
	return Height(root);
}

template<class K, class V>
bool AVLTree<K, V>::IsBalanced()
{
	return Is_Balanced(root);
}

template<class K, class V>
AVLTreeNode<K, V>* AVLTree<K, V>::Rotate_L(Node* p)
{
	Node* c = p->right;
	Node* parent = p->parent;

	p->right = c->left;
	if (c->left != nullptr)
	{
		c->left->parent = p;
	}
	c->left = p;
	p->parent = c;
	c->parent = parent;

	Update_Parent_Child(parent, p, c);

	p->balance = p->balance - 1 - std::max(0, c->balance);
	c->balance = c->balance - 1 + std::min(0, p->balance);

	return c;
}

template<class K, class V>
AVLTreeNode<K, V>* AVLTree<K, V>::Rotate_R(Node* p)
{
	Node* c = p->left;
	Node* parent = p->parent;

	p->left = c->right;
	if (c->right != nullptr)
	{
		c->right->parent = p;
	}
	c->right = p;
	p->parent = c;
	c->parent = parent;

	Update_Parent_Child(parent, p, c);


	p->balance = p->balance + 1 - std::min(0, c->balance);
	c->balance = c->balance + 1 + std::max(0, p->balance);

	return c;
}
template<class K, class V>
AVLTreeNode<K, V>* AVLTree<K, V>::Rotate_RL(Node* p)
{
	p->right = Rotate_R(p->right);
	return Rotate_L(p);
}
template<class K, class V>
AVLTreeNode<K, V>* AVLTree<K, V>::Rotate_LR(Node* p)
{
	p->left = Rotate_L(p->left);
	return Rotate_R(p);
}
template<class K, class V>
void AVLTree<K, V>::Rebalance_After_Insert(Node* parent, Node* insert_node)
{
	Node* cur = parent;
	Node* child = insert_node;

	while (cur != nullptr)
	{
		if (child == cur->left)
		{
			cur->balance--;
		}
		else
		{
			cur->balance++;
		}
		if (cur->balance == 0)
		{
			break;
		}

		if (cur->balance == 2 || cur->balance == -2)
		{
			Rebalance(cur);
			break;
		}
		child = cur;
		cur = cur->parent;
	}
}
template<class K, class V>
void AVLTree<K, V>::Rebalance_After_Remove(Node* cur)
{
	while (cur != nullptr)
	{
		if (cur->balance == 2 || cur->balance == -2)
		{
			Node* new_subtree_root = Rebalance(cur);
	
			if (new_subtree_root->balance != 0)
			{
				break;
			}
			cur = new_subtree_root->parent;
		}
		else
		{
			if (cur->balance != 0)
			{
				break;
			}

			Node* parent = cur->parent;
			if (parent != nullptr)
			{
				if (cur == parent->left)
				{
					parent->balance++;
				}
				else
				{
					parent->balance--;
				}
			}
			cur = parent;
		}
	}
}
template<class K, class V>
AVLTreeNode<K, V>* AVLTree<K, V>::Rebalance(Node* p)
{
	if (p->balance == 2) 
	{
		if (p->right->balance >= 0) 
		{
			return Rotate_L(p);
		}
		else 
		{
			return Rotate_RL(p);
		}
	}
	else if (p->balance == -2) 
	{
		if (p->left->balance <= 0) 
		{
			return Rotate_R(p);
		}
		else 
		{
			return Rotate_LR(p);
		}
	}
	return p; 
}
template<class K, class V>
AVLTreeNode<K, V>* AVLTree<K, V>:: Remove_Node(Node* target)
{
	Node* child = nullptr;
	Node* parent = target->parent;
	int balance_change = 0; 

	if (target->left == nullptr || target->right == nullptr)
	{
		child = (target->left != nullptr) ? target->left : target->right;

		if (parent != nullptr)
		{
			if (target == parent->left)
			{
				balance_change = 1;
			}
			else
			{
				balance_change = -1;
			}
		}

		Update_Parent_Child(parent, target, child);
		if (child != nullptr)
		{
			child->parent = parent;
		}
		delete target;
	}
	else
	{
		Node* successor = target->right;
		while (successor->left != nullptr)
		{
			successor = successor->left;
		}
		target->key = successor->key;
		target->value = successor->value;

		parent = successor->parent;
		if (successor == parent->left)
		{
			balance_change = 1;
		}
		else
		{
			balance_change = -1;
		}

		Update_Parent_Child(parent, successor, successor->right);
		if (successor->right != nullptr)
		{
			successor->right->parent = parent;
		}

		delete successor;
	}

	if (parent != nullptr) 
	{
		parent->balance += balance_change;
	}

	return parent; 
}
template<class K, class V>
void AVLTree<K, V>::Update_Parent_Child(Node* parent, Node* old_child, Node* new_child)
{
	if (parent == nullptr)
	{
		root = new_child;
	}
	else if (parent->left == old_child)
	{
		parent->left = new_child;
	}
	else
	{
		parent->right = new_child;
	}
}
template<class K, class V>
void  AVLTree<K, V>::Destroy(Node* node)
{
	if (node != nullptr)
	{
		Destroy(node->left);
		Destroy(node->right);
		delete node;
	}
}
template<class K, class V>
int AVLTree<K, V>::Height(Node* node)
{
	if (node == nullptr)
	{
		return -1;
	}
	return 1 + std::max(Height(node->left), Height(node->right));
}
template<class K, class V>
bool AVLTree<K, V>::Is_Balanced(Node* node)
{
	if (node == nullptr)
	{
		return true;
	}
	int left_height = Height(node->left);
	int right_height = Height(node->right);

	if (abs(right_height - left_height) <= 1 && node->balance == (right_height - left_height) && Is_Balanced(node->left) && Is_Balanced(node->right))
	{
		return true;
	}
	return false;
}
template class AVLTree<int, int>;