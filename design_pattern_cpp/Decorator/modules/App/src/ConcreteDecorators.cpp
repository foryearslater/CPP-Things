#include "ConcreteDecorators.hpp"

MilkDecorator::MilkDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}

double MilkDecorator::GetCost() const 
{
    return CoffeeDecorator::GetCost() + 2.0; 
}

std::string MilkDecorator::GetDescription() const 
{
    return CoffeeDecorator::GetDescription() + ", Milk";
}


SugarDecorator::SugarDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}

double SugarDecorator::GetCost() const 
{
    return CoffeeDecorator::GetCost() + 1.0; 
}

std::string SugarDecorator::GetDescription() const 
{
    return CoffeeDecorator::GetDescription() + ", Sugar";
}