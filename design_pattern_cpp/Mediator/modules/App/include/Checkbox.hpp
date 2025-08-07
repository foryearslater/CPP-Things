#pragma once
#include "UIComponent.hpp" 
#include <iostream>

/**
 * @class Checkbox
 * @brief 具体组件: 表示一个复选框
 * @detail 勾选状态改变时通知中介者
 */
class Checkbox : public UIComponent
{
public:
    explicit Checkbox(const std::string &name);

    ~Checkbox() override;

    void SetChecked(bool checked);

    bool IsChecked() const;

private:
    bool m_checked;
};