#pragma once
#include <string>

class UIComponent;

enum class EventType
{
    TextChange,   // 文本框内容改变
    Click,        // 按钮点击
    CheckedChange // 复选框状态改变
};

/**
 * @class IDialogMediator
 * @brief 抽象中介者接口:定义了组件与中介者通信的接口
 * @detail 所有具体组件都通过此接口通知中介者, 中介者通过此接口协调组件
 */

class IDialogMediator
{
public:
    virtual ~IDialogMediator() = default;

    virtual void Notify(UIComponent *sender, EventType event) = 0;
};