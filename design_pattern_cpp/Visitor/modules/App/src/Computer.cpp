#include "Computer.hpp"
#include <iostream>

Computer::Computer()
{
    std::cout << "Computer created." << std::endl;
}

Computer::~Computer()
{
    std::cout << "Computer destroyed." << std::endl;
}

void Computer::Accept(ComputerPartVisitor *visitor)
{

    visitor->Visit(this);

    for (const auto &part : m_parts)
    {
        part->Accept(visitor);
    }
}

void Computer::AddPart(std::unique_ptr<ComputerPart> part)
{
    m_parts.push_back(std::move(part));
}