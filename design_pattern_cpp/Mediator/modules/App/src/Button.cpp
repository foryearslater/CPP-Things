#include "Button.hpp"

Button::Button(const std::string &name) : UIComponent(name), m_enabled(false)
{
    std::cout << GetName() << " Button created." << std::endl;
}

Button::~Button()
{
    std::cout << GetName() << " Button destroyed." << std::endl;
}

void Button::Click()
{
    if (m_enabled)
    {
        std::cout << GetName() << " Button clicked!" << std::endl;
        if (m_mediator)
        {
            m_mediator->Notify(this, EventType::Click);
        }
    }
    else
    {
        std::cout << GetName() << " Button is disabled. Cannot click." << std::endl;
    }
}

void Button::SetEnabled(bool enabled)
{
    if (m_enabled != enabled)
    {
        m_enabled = enabled;
        std::cout << GetName() << " Button is now " << (m_enabled ? "ENABLED" : "DISABLED") << "." << std::endl;
    }
}

bool Button::IsEnabled() const
{
    return m_enabled;
}