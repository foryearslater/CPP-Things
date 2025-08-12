#include "SkipList.hpp"
#include <vector>
#include <stdexcept>
#include <chrono>

template <typename TKey, typename TValue>
SkipListNode<TKey, TValue>::SkipListNode(TKey k, TValue v, int level)
    : key(k), value(v), forward(level + 1, nullptr)
{
}

template <typename TKey, typename TValue>
SkipListNode<TKey, TValue>::~SkipListNode()
{
}

template <typename TKey, typename TValue>
SkipList<TKey, TValue>::SkipList()
    : level(0),
      head(new SkipListNode<TKey, TValue>(std::numeric_limits<TKey>::min(), TValue(), MAX_LEVEL)),
      rng(std::chrono::high_resolution_clock::now().time_since_epoch().count()),
      dist(0.0, 1.0)
{
    std::cout << "SkipList created. Max Level: " << MAX_LEVEL << ", Probability P: " << P << std::endl;
}

template <typename TKey, typename TValue>
SkipList<TKey, TValue>::~SkipList()
{
    SkipListNode<TKey, TValue> *cur = head->forward[0];
    while (cur != nullptr)
    {
        SkipListNode<TKey, TValue> *next = cur->forward[0];
        delete cur;
        cur = next;
    }
    delete head;
    std::cout << "SkipList destroyed." << std::endl;
}

template <typename TKey, typename TValue>
SkipListNode<TKey, TValue> *SkipList<TKey, TValue>::CreateNode(TKey key, TValue value, int level)
{
    return new SkipListNode<TKey, TValue>(key, value, level);
}

template <typename TKey, typename TValue>
int SkipList<TKey, TValue>::RandomLevel()
{
    int new_level = 0;
    while (dist(rng) < P && new_level < MAX_LEVEL)
    {
        new_level++;
    }
    return new_level;
}

template <typename TKey, typename TValue>
bool SkipList<TKey, TValue>::Search(TKey key, TValue &value)
{
    SkipListNode<TKey, TValue> *cur = head;

    for (int i = level; i >= 0; i--)
    {
        while (cur->forward[i] != nullptr && cur->forward[i]->key < key)
        {
            cur = cur->forward[i];
        }
    }

    cur = cur->forward[0];

    if (cur != nullptr && cur->key == key)
    {
        value = cur->value;
        return true;
    }

    return false;
}

template <typename TKey, typename TValue>
bool SkipList<TKey, TValue>::Insert(TKey key, TValue value)
{
    std::vector<SkipListNode<TKey, TValue> *> update(MAX_LEVEL + 1, nullptr);
    SkipListNode<TKey, TValue> *cur = head;

    for (int i = level; i >= 0; i--)
    {
        while (cur->forward[i] != nullptr && cur->forward[i]->key < key)
        {
            cur = cur->forward[i];
        }
        update[i] = cur;
    }

    cur = cur->forward[0];
    if (cur != nullptr && cur->key == key)
    {
        return false;
    }

    int new_level = RandomLevel();

    if (new_level > level)
    {
        for (int i = level + 1; i <= new_level; i++)
        {
            update[i] = head;
        }
        level = new_level;
    }

    SkipListNode<TKey, TValue> *new_node = CreateNode(key, value, new_level);

    for (int i = 0; i <= new_level; i++)
    {
        new_node->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = new_node;
    }

    return true;
}

template <typename TKey, typename TValue>
bool SkipList<TKey, TValue>::Delete(TKey key)
{
    std::vector<SkipListNode<TKey, TValue> *> update(MAX_LEVEL + 1, nullptr);
    SkipListNode<TKey, TValue> *cur = head;

    for (int i = level; i >= 0; i--)
    {
        while (cur->forward[i] != nullptr && cur->forward[i]->key < key)
        {
            cur = cur->forward[i];
        }
        update[i] = cur;
    }

    cur = cur->forward[0];
    if (cur == nullptr || cur->key != key)
    {
        return false;
    }

    for (int i = 0; i <= level; i++)
    {
        if (update[i]->forward[i] == cur)
        {
            update[i]->forward[i] = cur->forward[i];
        }
    }

    delete cur;

    while (level > 0 && head->forward[level] == nullptr)
    {
        level--;
    }

    std::cout << "Deleted key " << key << "." << std::endl;
    return true;
}

template <typename TKey, typename TValue>
void SkipList<TKey, TValue>::Display()
{
    std::cout << "\n--- SkipList Display ---" << std::endl;
    for (int i = level; i >= 0; i--)
    {
        std::cout << "Level " << i << ": ";
        SkipListNode<TKey, TValue> *node = head->forward[i];
        while (node != nullptr)
        {
            std::cout << "[" << node->key << ":" << node->value << "] -> ";
            node = node->forward[i];
        }
        std::cout << "nullptr" << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
}

template class SkipListNode<int, int>;
template class SkipList<int, int>;