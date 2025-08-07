#pragma once

class Keyboard;
class Monitor;
class Computer;
class Mouse;

/**
 * @class ComputerPartVisitor
 * @brief 抽象访问者：定义了访问（操作）结构中每个元素类型的接口
 * @detail 每个具体访问者都必须实现此接口
 */
class ComputerPartVisitor
{
public:
    virtual ~ComputerPartVisitor() = default;

    virtual void Visit(Keyboard *keyboard) = 0;

    virtual void Visit(Monitor *monitor) = 0;

    virtual void Visit(Computer *computer) = 0;

    virtual void Visit(Mouse *mouse) = 0;
};