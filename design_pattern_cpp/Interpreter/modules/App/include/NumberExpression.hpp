#pragma once
#include "Expression.hpp"
#include <string>

/**
 * @class NumberExpression
 * @brief 终结符表达式：表示语法中的一个终结符
 * @detail 实现了Expression接口，其Interpret方法直接返回自身的值
 */
class NumberExpression : public Expression
{
public:
    explicit NumberExpression(int value);

    ~NumberExpression() override;

    int Interpret(Context &context) const override;

    std::string ToString() const override;

private:
    int m_value;
};