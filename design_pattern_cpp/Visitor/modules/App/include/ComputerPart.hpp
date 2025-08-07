#pragma once
#include <memory>

class ComputerPartVisitor;

/**
 * @class ComputerPart
 * @brief 抽象元素：定义了接受访问者对象的接口
 * @detail 所有具体元素（计算机组件）都必须实现此接口，以便访问者可以访问它们
 */
class ComputerPart
{
public:

    virtual ~ComputerPart() = default;

    virtual void Accept(ComputerPartVisitor *visitor) = 0;
    
};