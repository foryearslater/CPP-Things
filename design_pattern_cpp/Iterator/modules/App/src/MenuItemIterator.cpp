#include "MenuItemIterator.hpp"
#include <stdexcept>

MenuItemIterator::MenuItemIterator(const std::vector<MenuItem> &items)
    : m_items(items), m_position(0)
{
    std::cout << "MenuItemIterator created." << std::endl;
}

MenuItemIterator::~MenuItemIterator()
{
    std::cout << "MenuItemIterator destroyed." << std::endl;
}

bool MenuItemIterator::HasNext() const
{
    return m_position < m_items.size();
}

const MenuItem &MenuItemIterator::Next()
{
    if (!HasNext())
    {
        throw std::out_of_range("Iterator out of bounds. No more elements.");
    }
    return m_items[m_position++];
}