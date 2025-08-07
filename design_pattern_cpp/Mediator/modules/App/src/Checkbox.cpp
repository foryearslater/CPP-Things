#include "Checkbox.hpp"

Checkbox::Checkbox(const std::string &name) : UIComponent(name), m_checked(false)
{
    std::cout << GetName() << " Checkbox created." << std::endl;
}

Checkbox::~Checkbox()
{
    std::cout << GetName() << " Checkbox destroyed." << std::endl;
}

void Checkbox::SetChecked(bool checked)
{
    if (m_checked != checked)
    {
        m_checked = checked;
        std::cout << GetName() << " Checkbox set to " << (m_checked ? "CHECKED" : "UNCHECKED") << "." << std::endl;
        if (m_mediator)
        {
            m_mediator->Notify(this, EventType::CheckedChange);
        }
    }
}

bool Checkbox::IsChecked() const
{
    return m_checked;
}