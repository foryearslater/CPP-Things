#pragma once
#include "MenuItem.hpp"

/**
 * @class Iterator
 * @brief 抽象迭代器:定义了访问和遍历集合元素的接口
 * @detail 所有具体迭代器都必须实现此接口
 */
class Iterator
{
public:
    virtual ~Iterator() = default;

    virtual bool HasNext() const = 0;

    virtual const MenuItem &Next() = 0;
};