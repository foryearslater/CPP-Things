#pragma once
#include "IDialogMediator.hpp"
#include <iostream>
#include <memory>

#include "Button.hpp"
#include "TextBox.hpp"
#include "Checkbox.hpp"

/**
 * @class LoginDialogMediator
 * @brief 具体中介者: 协调登录对话框中UI组件的交互
 * @detail 知道所有组件, 并根据业务逻辑协调它们的行为
 */
class LoginDialogMediator : public IDialogMediator
{
public:
    LoginDialogMediator();

    ~LoginDialogMediator() override;

    void SetComponents(TextBox *usernameBox, TextBox *passwordBox, Checkbox *termsCheckbox, Button *submitButton);

    void Notify(UIComponent *sender, EventType event) override;

private:
    TextBox *m_usernameBox = nullptr;
    TextBox *m_passwordBox = nullptr;
    Checkbox *m_termsCheckbox = nullptr;
    Button *m_submitButton = nullptr;

    void UpdateSubmitButtonState();
};