#pragma once
#include "Iterator.hpp"
#include <vector>

/**
 * @class MenuItemIterator
 * @brief 具体迭代器:实现了迭代器接口,用于遍历MenuItem的std::vector集合
 * @detail 知道如何遍历DinerMenu内部的MenuItem集合
 */
class MenuItemIterator : public Iterator
{
public:
    explicit MenuItemIterator(const std::vector<MenuItem>& items);

    ~MenuItemIterator() override;

    bool HasNext() const override;

    const MenuItem& Next() override;

private:
    const std::vector<MenuItem>& m_items;
    mutable int m_position;
};