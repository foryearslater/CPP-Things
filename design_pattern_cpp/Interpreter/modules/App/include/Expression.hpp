#pragma once
#include <memory>      
#include "Context.hpp" 

/**
 * @class Expression
 * @brief 抽象表达式：定义了所有表达式的解释操作
 * @detail 所有具体表达式类都必须实现此接口
 */
class Expression
{
public:
    virtual ~Expression() = default;

    virtual int Interpret(Context &context) const = 0;

    virtual std::string ToString() const = 0;
};