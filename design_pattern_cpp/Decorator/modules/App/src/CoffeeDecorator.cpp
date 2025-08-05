#include "CoffeeDecorator.hpp"

CoffeeDecorator::CoffeeDecorator(std::shared_ptr<Coffee> coffee) : m_coffee(coffee) {}

double CoffeeDecorator::GetCost() const 
{
    if (m_coffee)
    {
        return m_coffee->GetCost();
    }
    return 0.0;
}

std::string CoffeeDecorator::GetDescription() const 
{

    if (m_coffee) 
    {
        return m_coffee->GetDescription();
    }
    return "Unknown Coffee";
}