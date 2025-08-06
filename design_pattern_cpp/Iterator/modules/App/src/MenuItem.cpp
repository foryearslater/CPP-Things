#include "MenuItem.hpp"
#include <iomanip>

MenuItem::MenuItem(const std::string &name, const std::string &description, bool vegetarian, double price)
    : m_name(name), m_description(description), m_vegetarian(vegetarian), m_price(price)
{
    std::cout << "MenuItem created: " << m_name << std::endl;
}

MenuItem::~MenuItem()
{
    std::cout << "MenuItem destroyed: " << m_name << std::endl;
}

std::string MenuItem::GetName() const
{
    return m_name;
}

std::string MenuItem::GetDescription() const
{
    return m_description;
}

double MenuItem::GetPrice() const
{
    return m_price;
}

bool MenuItem::IsVegetarian() const
{
    return m_vegetarian;
}

std::string MenuItem::ToString() const
{
    std::stringstream ss;
    ss << m_name;
    if (m_vegetarian)
    {
        ss << " (v)";
    }
    ss << ", " << std::fixed << std::setprecision(2) << m_price;
    ss << " -- " << m_description;
    return ss.str();
}