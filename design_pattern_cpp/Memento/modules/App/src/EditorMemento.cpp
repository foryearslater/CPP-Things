#include "EditorMemento.hpp"

EditorMemento::EditorMemento(const std::string& text) : m_text(text) 
{
    std::cout << "EditorMemento created for text: \"" << m_text << "\"" << std::endl;
}


EditorMemento::~EditorMemento() 
{
    std::cout << "EditorMemento destroyed for text: \"" << m_text << "\"" << std::endl;
}