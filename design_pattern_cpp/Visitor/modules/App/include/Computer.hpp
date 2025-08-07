#pragma once
#include "ComputerPart.hpp"
#include "ComputerPartVisitor.hpp"
#include <vector>
#include <memory>

/**
 * @class Computer
 * @brief 具体元素：表示计算机本身，它是一个复合组件
 * @detail 实现了ComputerPart接口，并包含其他ComputerPart作为子部件
 */

class Computer : public ComputerPart
{
public:
    Computer();

    ~Computer() override;

    void Accept(ComputerPartVisitor *visitor) override;

    void AddPart(std::unique_ptr<ComputerPart> part);

private:

    std::vector<std::unique_ptr<ComputerPart>> m_parts;
    
};