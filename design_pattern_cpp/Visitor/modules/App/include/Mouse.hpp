#pragma once
#include "ComputerPart.hpp"
#include "ComputerPartVisitor.hpp"

/**
 * @class Mouse
 * @brief 具体元素：表示计算机的鼠标组件
 * @detail 实现了ComputerPart接口，定义了接受访问者的方法
 */
class Mouse : public ComputerPart
{
public:

    Mouse();

    ~Mouse() override;

    void Accept(ComputerPartVisitor *visitor) override;
    
};