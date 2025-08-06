#pragma once
#include <memory>
#include "Iterator.hpp"

/**
 * @class Menu
 * @brief 抽象聚合:定义了创建迭代器对象的接口
 * @detail 所有具体菜单（聚合）都必须实现此接口,以便客户端能够获取其迭代器
 */
class Menu
{
public:
    virtual ~Menu() = default;

    virtual std::unique_ptr<Iterator> CreateIterator() const = 0;
};