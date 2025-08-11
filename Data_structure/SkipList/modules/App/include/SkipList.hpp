/**
 * @file SkipList.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  跳表模板类实现
 * @version 0.1
 * @date 2025-08-11
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <random>
#include <limits>

template <typename TKey, typename TValue>
class SkipList;

/**
 * @class SkipListNode
 * @brief 跳表中的一个节点.
 * @detail 包含键、值以及一个指向其在各个层级下一个节点的指针数组.
 */
template <typename TKey, typename TValue>
class SkipListNode
{
public:
    TKey key;
    TValue value;

    // point next
    std::vector<SkipListNode<TKey, TValue> *> forward;

    SkipListNode(TKey k, TValue v, int level);

    ~SkipListNode();

    bool IsHead() const
    {
        return key == std::numeric_limits<TKey>::min();
    }
};

/**
 * @class SkipList
 * @brief 跳表的实现
 * @detail 提供插入、查找、删除等基本操作，这些操作的平均时间复杂度为O(log n), 通过随机层级和多层链表结构实现高效的查找
 */

template <typename TKey, typename TValue>
class SkipList
{
public:
    SkipList();

    ~SkipList();

    /**
     * @brief 在跳表中查找指定键值对应的元素.
     * @param key 要查找的键.
     * @param value 查找到的值，通过引用返回.如果找到，此参数将被赋值.
     * @return 如果在跳表中找到匹配的键，返回true；否则返回false
     */

    bool Search(TKey key, TValue &value);

    /**
     * @brief 向跳表中插入一个新的键值对
     * @param key 要插入的键
     * @param value 要插入的值
     * @return 如果成功插入（键在跳表中不存在），返回true；如果键已存在且不允许重复，返回false
     */

    bool Insert(TKey key, TValue value);

    /**
     * @brief 从跳表中删除指定键值对.
     * @param key 要删除的键.
     * @return 如果成功删除，返回true；如果键在跳表中不存在，返回false.
     */

    bool Delete(TKey key);

    /**
     * @brief 打印跳表的当前结构，用于调试和可视化.
     * @detail 会显示每一层链表的连接情况.
     */

    void Display();

public:
    static const int MAX_LEVEL = 16; // 跳表支持的最大层级
    static constexpr double P = 0.5; // 随机层级生成的概率因子

private:
    int level;
    SkipListNode<TKey, TValue> *head;
    std::mt19937_64 rng;
    std::uniform_real_distribution<double> dist;

    int RandomLevel();

    /**
     * @brief 内部辅助函数：创建并返回一个新的SkipListNode.
     * @param key 节点的键.
     * @param value 节点的值.
     * @param level 节点应被创建的层级.
     * @return 指向新创建节点的指针.
     */

    SkipListNode<TKey, TValue> *CreateNode(TKey key, TValue value, int level);
};