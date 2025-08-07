#include "Quack.hpp"

Quack::Quack()
{
    std::cout << "Quack strategy created." << std::endl;
}

Quack::~Quack()
{
    std::cout << "Quack strategy destroyed." << std::endl;
}

void Quack::QuackNow() const
{
    std::cout << "Quack! Quack!" << std::endl;
}