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
{
    :   level(0), 
        head(new SkipListNode<TKey, TValue>(std::numeric_limits<TKey>::min(), TValue(), MAX_LEVEL)), 
        rng(std::chrono::high_resolution_clock::now().time_since_epoch().count()),
    std::cout << "SkipList created. Max Level: " << MAX_LEVEL << ", Probability P: " << P << std::endl;
}

template <typename TKey, typename TValue>
SkipList<TKey, TValue>::~SkipList()
{
    SkipListNode<TKey, TValue> *current = head->forward[0];
    while (current != nullptr)
    {
        SkipListNode<TKey, TValue> *next = current->forward[0];
        delete current;
        current = next;
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
    int newLevel = 0;
    while (dist(rng) < P && newLevel < MAX_LEVEL)
    {
        newLevel++;
    }
    return newLevel;
}

template <typename TKey, typename TValue>
bool SkipList<TKey, TValue>::Search(TKey key, TValue &value)
{
    SkipListNode<TKey, TValue> *current = head;

    for (int i = level; i >= 0; i--)
    {
        while (current->forward[i] != nullptr && current->forward[i]->key < key)
        {
            current = current->forward[i];
        }
    }

    current = current->forward[0];

    if (current != nullptr && current->key == key)
    {
        value = current->value;
        return true;
    }

    return false;
}

template <typename TKey, typename TValue>
bool SkipList<TKey, TValue>::Insert(TKey key, TValue value)
{
    std::vector<SkipListNode<TKey, TValue> *> update(MAX_LEVEL + 1, nullptr);
    SkipListNode<TKey, TValue> *current = head;

    for (int i = level; i >= 0; i--)
    {
        while (current->forward[i] != nullptr && current->forward[i]->key < key)
        {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];
    if (current != nullptr && current->key == key)
    {
        return false;
    }

    int newLevel = randomLevel();

    if (newLevel > level)
    {
        for (int i = level + 1; i <= newLevel; i++)
        {
            update[i] = head;
        }
        level = newLevel;
    }

    SkipListNode<TKey, TValue> *newNode = createNode(key, value, newLevel);

    for (int i = 0; i <= newLevel; i++)
    {
        newNode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;
    }

    return true;
}

template <typename TKey, typename TValue>
bool SkipList<TKey, TValue>::Delete(TKey key)
{
    std::vector<SkipListNode<TKey, TValue> *> update(MAX_LEVEL + 1, nullptr);
    SkipListNode<TKey, TValue> *current = head;

    for (int i = level; i >= 0; i--)
    {
        while (current->forward[i] != nullptr && current->forward[i]->key < key)
        {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];
    if (current == nullptr || current->key != key)
    {
        return false;
    }

    for (int i = 0; i <= level; i++)
    {
        if (update[i]->forward[i] == current)
        {
            update[i]->forward[i] = current->forward[i];
        }
    }

    delete current;

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