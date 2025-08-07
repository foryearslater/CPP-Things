#pragma once
#include "UIComponent.hpp"
#include <iostream>

/**
 * @class Button
 * @brief 具体组件: 表示一个按钮
 * @detail 具有启用/禁用状态, 点击时通知中介者
 */
class Button : public UIComponent
{
public:
    explicit Button(const std::string &name);

    ~Button() override;

    void Click();

    void SetEnabled(bool enabled);

    bool IsEnabled() const;

private:
    bool m_enabled;
};