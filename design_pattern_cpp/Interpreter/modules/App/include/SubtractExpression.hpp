#pragma once
#include "Expression.hpp"
#include <memory>

/**
 * @class SubtractExpression
 * @brief 非终结符表达式：表示语法中的一个操作
 * @detail 包含两个子表达式, 其Interpret方法解释这两个子表达式并执行减法
 */
class SubtractExpression : public Expression
{
public:
    SubtractExpression(std::unique_ptr<Expression> leftExpr, std::unique_ptr<Expression> rightExpr);

    ~SubtractExpression() override;

    int Interpret(Context &context) const override;

    std::string ToString() const override;

private:
    std::unique_ptr<Expression> m_leftExpr;
    std::unique_ptr<Expression> m_rightExpr;
};