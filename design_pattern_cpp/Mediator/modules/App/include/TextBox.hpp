#pragma once
#include "UIComponent.hpp" // 包含抽象组件基类
#include <string>
#include <iostream>

/**
 * @class TextBox
 * @brief 具体组件：表示一个文本输入
 * @detail 文本内容改变时通知中介
 */
class TextBox : public UIComponent
{
public:
    explicit TextBox(const std::string &name);

    ~TextBox() override;

    void SetText(const std::string &text);

    std::string GetText() const;

private:
    std::string m_text;
};