#include "TextBox.hpp"

TextBox::TextBox(const std::string &name) : UIComponent(name), m_text("")
{
    std::cout << GetName() << " TextBox created." << std::endl;
}

TextBox::~TextBox()
{
    std::cout << GetName() << " TextBox destroyed." << std::endl;
}

void TextBox::SetText(const std::string &text)
{
    if (m_text != text)
    {
        m_text = text;
        std::cout << GetName() << " TextBox text set to: \"" << m_text << "\"" << std::endl;
        if (m_mediator)
        {
            m_mediator->Notify(this, EventType::TextChange); 
        }
    }
}

std::string TextBox::GetText() const
{
    return m_text;
}