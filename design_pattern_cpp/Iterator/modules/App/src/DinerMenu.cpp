#include "DinerMenu.hpp"
#include "MenuItemIterator.hpp"

DinerMenu::DinerMenu()
{
    std::cout << "DinerMenu created." << std::endl;
    AddItem("Vegetarian BLT", "(Fakin') Bacon with lettuce & tomato on whole wheat", true, 2.99);
    AddItem("BLT", "Bacon with lettuce & tomato on whole wheat", false, 2.99);
    AddItem("Soup of the day", "A bowl of the soup of the day, with a side of potato salad", false, 3.29);
    AddItem("Hotdog", "A hot dog, with sauerkraut, relish, onions, topped with cheese", false, 3.05);
}

DinerMenu::~DinerMenu()
{
    std::cout << "DinerMenu destroyed." << std::endl;
}

void DinerMenu::AddItem(const std::string &name, const std::string &description, bool vegetarian, double price)
{
    m_menuItems.emplace_back(name, description, vegetarian, price);
    std::cout << "Added item: " << name << std::endl;
}

std::unique_ptr<Iterator> DinerMenu::CreateIterator() const
{
    return std::make_unique<MenuItemIterator>(m_menuItems);
}