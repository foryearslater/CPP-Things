#pragma once
#include "Menu.hpp"
#include <vector>
#include <iostream>

/**
 * @class DinerMenu
 * @brief 具体聚合:表示一个晚餐菜单。
 * @detail 实现了Menu接口,并维护一个MenuItem的集,负责提供创建MenuItemIterator的方法
 *
 **/
class DinerMenu : public Menu
{
public:
    DinerMenu();

    ~DinerMenu() override;

    void AddItem(const std::string &name, const std::string &description, bool vegetarian, double price);

    std::unique_ptr<Iterator> CreateIterator() const override;

private:
    std::vector<MenuItem> m_menuItems;
};