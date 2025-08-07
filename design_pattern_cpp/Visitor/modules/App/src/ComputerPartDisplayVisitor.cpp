#include "ComputerPartDisplayVisitor.hpp"
#include <iostream>

ComputerPartDisplayVisitor::ComputerPartDisplayVisitor()
{
    std::cout << "ComputerPartDisplayVisitor created." << std::endl;
}

ComputerPartDisplayVisitor::~ComputerPartDisplayVisitor()
{
    std::cout << "ComputerPartDisplayVisitor destroyed." << std::endl;
}

void ComputerPartDisplayVisitor::Visit(Keyboard *keyboard)
{
    if (keyboard)
    {
        std::cout << "Displaying Keyboard." << std::endl;
    }
}

void ComputerPartDisplayVisitor::Visit(Monitor *monitor)
{
    if (monitor)
    {
        std::cout << "Displaying Monitor." << std::endl;
    }
}

void ComputerPartDisplayVisitor::Visit(Computer *computer)
{
    if (computer)
    {
        std::cout << "Displaying Computer." << std::endl;
    }
}

void ComputerPartDisplayVisitor::Visit(Mouse *mouse)
{
    if (mouse)
    {
        std::cout << "Displaying Mouse." << std::endl;
    }
}