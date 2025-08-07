#include "Monitor.hpp"
#include <iostream>

Monitor::Monitor()
{
    std::cout << "Monitor created." << std::endl;
}

Monitor::~Monitor()
{
    std::cout << "Monitor destroyed." << std::endl;
}

void Monitor::Accept(ComputerPartVisitor *visitor)
{
    visitor->Visit(this);
}