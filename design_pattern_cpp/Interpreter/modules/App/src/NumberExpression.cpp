#include "NumberExpression.hpp"
#include <string>
#include <iostream>

NumberExpression::NumberExpression(int value) : m_value(value) 
{
    std::cout << "NumberExpression created: " << m_value << std::endl;
}


NumberExpression::~NumberExpression()
 {
    std::cout << "NumberExpression destroyed: " << m_value << std::endl;
}


int NumberExpression::Interpret(Context& context) const 
{
    return m_value;
}

std::string NumberExpression::ToString() const 
{
    return std::to_string(m_value);
}