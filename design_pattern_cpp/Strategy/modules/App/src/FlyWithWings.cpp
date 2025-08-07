#include "FlyWithWings.hpp"

FlyWithWings::FlyWithWings()
{
    std::cout << "FlyWithWings strategy created." << std::endl;
}

FlyWithWings::~FlyWithWings()
{
    std::cout << "FlyWithWings strategy destroyed." << std::endl;
}

void FlyWithWings::Fly() const
{
    std::cout << "Flying with wings!" << std::endl;
}