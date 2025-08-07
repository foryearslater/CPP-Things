#pragma once
#include "ComputerPart.hpp"
#include "ComputerPartVisitor.hpp"

/**
 * @class Monitor
 * @brief 具体元素：表示计算机的显示器组件
 * @detail 实现了ComputerPart接口，定义了接受访问者的方法
 */
class Monitor : public ComputerPart
{
public:

    Monitor();

    ~Monitor() override;

    void Accept(ComputerPartVisitor *visitor) override;
    
};