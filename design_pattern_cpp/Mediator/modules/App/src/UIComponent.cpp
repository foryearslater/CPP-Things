#include "UIComponent.hpp"
#include <iostream>

UIComponent::UIComponent(const std::string &name) : m_name(name), m_mediator(nullptr)
{
    std::cout << m_name << " UIComponent created." << std::endl;
}

void UIComponent::SetMediator(IDialogMediator *mediator)
{
    m_mediator = mediator;
}

std::string UIComponent::GetName() const
{
    return m_name;
}