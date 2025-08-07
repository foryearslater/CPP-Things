#include "FlyNoWay.hpp"

FlyNoWay::FlyNoWay()
{
    std::cout << "FlyNoWay strategy created." << std::endl;
}

FlyNoWay::~FlyNoWay()
{
    std::cout << "FlyNoWay strategy destroyed." << std::endl;
}

void FlyNoWay::Fly() const
{
    std::cout << "Cannot fly!" << std::endl;
}