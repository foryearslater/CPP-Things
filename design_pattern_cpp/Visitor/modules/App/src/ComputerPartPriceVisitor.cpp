#include "ComputerPartPriceVisitor.hpp"

ComputerPartPriceVisitor::ComputerPartPriceVisitor() : m_totalPrice(0.0)
{
    std::cout << "ComputerPartPriceVisitor created." << std::endl;
}

ComputerPartPriceVisitor::~ComputerPartPriceVisitor()
{
    std::cout << "ComputerPartPriceVisitor destroyed." << std::endl;
}

void ComputerPartPriceVisitor::Visit(Keyboard *keyboard)
{
    if (keyboard)
    {
        m_totalPrice += 75.0;
        std::cout << "Calculating price for Keyboard: +$75.0" << std::endl;
    }
}

void ComputerPartPriceVisitor::Visit(Monitor *monitor)
{
    if (monitor)
    {
        m_totalPrice += 200.0;
        std::cout << "Calculating price for Monitor: +$200.0" << std::endl;
    }
}

void ComputerPartPriceVisitor::Visit(Computer *computer)
{
    if (computer)
    {
        m_totalPrice += 500.0;
        std::cout << "Calculating price for Computer (base): +$500.0" << std::endl;
    }
}

void ComputerPartPriceVisitor::Visit(Mouse *mouse)
{
    if (mouse)
    {
        m_totalPrice += 25.0;
        std::cout << "Calculating price for Mouse: +$25.0" << std::endl;
    }
}

double ComputerPartPriceVisitor::GetTotalPrice() const
{
    return m_totalPrice;
}