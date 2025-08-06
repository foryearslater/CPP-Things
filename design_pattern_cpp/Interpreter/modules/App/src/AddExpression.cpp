#include "AddExpression.hpp"
#include <iostream>

AddExpression::AddExpression(std::unique_ptr<Expression> leftExpr, std::unique_ptr<Expression> rightExpr)
    : m_leftExpr(std::move(leftExpr)), m_rightExpr(std::move(rightExpr))
{
    std::cout << "AddExpression created: " << m_leftExpr->ToString() << " + " << m_rightExpr->ToString() << std::endl;
}

AddExpression::~AddExpression()
{
    std::cout << "AddExpression destroyed." << std::endl;
}

int AddExpression::Interpret(Context &context) const
{
    return m_leftExpr->Interpret(context) + m_rightExpr->Interpret(context);
}

std::string AddExpression::ToString() const
{
    return "(" + m_leftExpr->ToString() + " + " + m_rightExpr->ToString() + ")";
}