#pragma once
#include "ComputerPartVisitor.hpp"
#include <iostream>
#include <iomanip>

#include "Keyboard.hpp"
#include "Monitor.hpp"
#include "Computer.hpp"
#include "Mouse.hpp"

/**
 * @class ComputerPartPriceVisitor
 * @brief 具体访问者：用于计算计算机组件的总价格
 * @detail 实现了ComputerPartVisitor接口，定义了访问不同组件时如何累加价格
 */
class ComputerPartPriceVisitor : public ComputerPartVisitor
{
public:
    ComputerPartPriceVisitor();

    ~ComputerPartPriceVisitor() override;

    void Visit(Keyboard *keyboard) override;

    void Visit(Monitor *monitor) override;

    void Visit(Computer *computer) override;

    void Visit(Mouse *mouse) override;

    double GetTotalPrice() const;

private:

    double m_totalPrice;
    
};