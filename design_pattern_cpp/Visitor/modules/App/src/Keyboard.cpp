#include "Keyboard.hpp"
#include <iostream>

Keyboard::Keyboard()
{
    std::cout << "Keyboard created." << std::endl;
}

Keyboard::~Keyboard()
{
    std::cout << "Keyboard destroyed." << std::endl;
}

void Keyboard::Accept(ComputerPartVisitor *visitor)
{
    visitor->Visit(this);
}