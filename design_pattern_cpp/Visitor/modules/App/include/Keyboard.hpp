#pragma once
#include "ComputerPart.hpp"
#include "ComputerPartVisitor.hpp"

/**
 * @class Keyboard
 * @brief 具体元素：表示计算机的键盘组件
 * @detail 实现了ComputerPart接口，定义了接受访问者的方法
 */
class Keyboard : public ComputerPart
{
public:

    Keyboard();

    ~Keyboard() override;

    void Accept(ComputerPartVisitor *visitor) override;
    
};