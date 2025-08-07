#include "LoginDialogMediator.hpp"

LoginDialogMediator::LoginDialogMediator()
{
    std::cout << "LoginDialogMediator created." << std::endl;
}

LoginDialogMediator::~LoginDialogMediator()
{
    std::cout << "LoginDialogMediator destroyed." << std::endl;
}

void LoginDialogMediator::SetComponents(TextBox *usernameBox, TextBox *passwordBox,
                                        Checkbox *termsCheckbox, Button *submitButton)
{
    m_usernameBox = usernameBox;
    m_passwordBox = passwordBox;
    m_termsCheckbox = termsCheckbox;
    m_submitButton = submitButton;

    m_usernameBox->SetMediator(this);
    m_passwordBox->SetMediator(this);
    m_termsCheckbox->SetMediator(this);
    m_submitButton->SetMediator(this);

    UpdateSubmitButtonState();
}

void LoginDialogMediator::Notify(UIComponent *sender, EventType event)
{
    std::cout << "Mediator: Received notification from " << sender->GetName() << " for event type ";
    if (event == EventType::TextChange)
        std::cout << "TextChange";
    else if (event == EventType::Click)
        std::cout << "Click";
    else if (event == EventType::CheckedChange)
        std::cout << "CheckedChange";
    std::cout << "." << std::endl;

    if (sender == m_usernameBox || sender == m_termsCheckbox)
    {

        UpdateSubmitButtonState();
    }
    else if (sender == m_submitButton && event == EventType::Click)
    {
        std::cout << "Mediator: Login attempt with username '" << m_usernameBox->GetText() << "'." << std::endl;
    }
}

void LoginDialogMediator::UpdateSubmitButtonState()
{
    bool enableSubmit = !m_usernameBox->GetText().empty() && m_termsCheckbox->IsChecked();
    if (m_submitButton->IsEnabled() != enableSubmit)
    {
        m_submitButton->SetEnabled(enableSubmit);
    }
}