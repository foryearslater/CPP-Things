#pragma once
#include <string>
#include <iostream>

/**
 * @class MenuItem
 * @brief 集合中的元素:表示菜单中的一道菜品
 * @detail 包含菜品的名称,价格和是否素食的属性
 */
class MenuItem
{
public:
    MenuItem(const std::string &name, const std::string &description, bool vegetarian, double price);

    ~MenuItem();

    std::string GetName() const;

    std::string GetDescription() const;

    double GetPrice() const;

    bool IsVegetarian() const;

    std::string ToString() const;

private:
    std::string m_name;
    std::string m_description;
    bool m_vegetarian;
    double m_price;
};