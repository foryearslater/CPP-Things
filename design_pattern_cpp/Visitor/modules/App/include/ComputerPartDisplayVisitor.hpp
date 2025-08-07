#pragma once
#include <iostream>

#include "ComputerPartVisitor.hpp"
#include "Keyboard.hpp"
#include "Monitor.hpp"
#include "Computer.hpp"
#include "Mouse.hpp"

/**
 * @class ComputerPartDisplayVisitor
 * @brief 具体访问者：用于显示计算机组件的信息
 * @detail 实现了ComputerPartVisitor接口，定义了访问不同组件时如何显示信息
 */
class ComputerPartDisplayVisitor : public ComputerPartVisitor
{
public:

    ComputerPartDisplayVisitor();

    ~ComputerPartDisplayVisitor() override;

    void Visit(Keyboard *keyboard) override;

    void Visit(Monitor *monitor) override;

    void Visit(Computer *computer) override;

    void Visit(Mouse *mouse) override;
    
};