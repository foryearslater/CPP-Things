#include "History.hpp"
#include <iostream>
#include <algorithm>

History::History()
{
    std::cout << "History (Caretaker) created." << std::endl;
}

History::~History()
{
    std::cout << "History (Caretaker) destroyed." << std::endl;
}

void History::Push(std::unique_ptr<EditorMemento> memento)
{
    if (memento)
    {
        m_mementos.push_back(std::move(memento));
        std::cout << "History: Pushed a memento. Current count: " << m_mementos.size() << std::endl;
    }
}

std::unique_ptr<EditorMemento> History::Pop()
{
    if (m_mementos.empty())
    {
        std::cout << "History: No mementos to pop." << std::endl;
        return nullptr;
    }
    std::unique_ptr<EditorMemento> poppedMemento = std::move(m_mementos.back());
    m_mementos.pop_back();
    std::cout << "History: Popped a memento. Remaining count: " << m_mementos.size() << std::endl;
    return poppedMemento;
}

size_t History::GetCount() const
{
    return m_mementos.size();
}