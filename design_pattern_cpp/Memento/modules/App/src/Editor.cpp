#include "Editor.hpp"
#include <iostream>

Editor::Editor(const std::string &initialText) : m_text(initialText)
{
    std::cout << "Editor created with initial text: \"" << m_text << "\"" << std::endl;
}

Editor::~Editor()
{
    std::cout << "Editor destroyed." << std::endl;
}

void Editor::SetText(const std::string &newText)
{
    m_text = newText;
    std::cout << "Editor: Text set to \"" << m_text << "\"" << std::endl;
}

std::string Editor::GetText() const
{
    return m_text;
}

std::unique_ptr<EditorMemento> Editor::Save() const
{
    std::cout << "Editor: Saving current state (\"" << m_text << "\")..." << std::endl;
    return std::make_unique<EditorMemento>(m_text);
}

void Editor::Restore(const EditorMemento *memento)
{
    if (memento)
    {
        m_text = memento->m_text;
        std::cout << "Editor: Restored state to \"" << m_text << "\"." << std::endl;
    }
    else
    {
        std::cerr << "Editor: Cannot restore from a null memento." << std::endl;
    }
}