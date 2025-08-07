#pragma once
#include <string>
#include <memory>

#include "IDialogMediator.hpp"

/**
 * @class UIComponent
 * @brief 抽象组件基类:定义了所有UI组件的通用接口,并持有对中介者的引用
 */

class UIComponent
{
public:
    explicit UIComponent(const std::string &name);

    virtual ~UIComponent() = default;

    void SetMediator(IDialogMediator *mediator);

    std::string GetName() const;

protected:
    IDialogMediator *m_mediator;
    std::string m_name;
};