#include "Mouse.hpp"
#include <iostream>

Mouse::Mouse()
{
    std::cout << "Mouse created." << std::endl;
}

Mouse::~Mouse()
{
    std::cout << "Mouse destroyed." << std::endl;
}

void Mouse::Accept(ComputerPartVisitor *visitor)
{
    visitor->Visit(this);
}