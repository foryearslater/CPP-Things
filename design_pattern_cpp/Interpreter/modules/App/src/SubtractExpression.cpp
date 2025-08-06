#include "SubtractExpression.hpp"
#include <iostream>

SubtractExpression::SubtractExpression(std::unique_ptr<Expression> leftExpr, std::unique_ptr<Expression> rightExpr)
    : m_leftExpr(std::move(leftExpr)), m_rightExpr(std::move(rightExpr))
{
    std::cout << "SubtractExpression created: " << m_leftExpr->ToString() << " - " << m_rightExpr->ToString() << std::endl;
}

SubtractExpression::~SubtractExpression()
{
    std::cout << "SubtractExpression destroyed." << std::endl;
}

int SubtractExpression::Interpret(Context &context) const
{
    return m_leftExpr->Interpret(context) - m_rightExpr->Interpret(context);
}

std::string SubtractExpression::ToString() const 
{
    return "(" + m_leftExpr->ToString() + " - " + m_rightExpr->ToString() + ")";
}