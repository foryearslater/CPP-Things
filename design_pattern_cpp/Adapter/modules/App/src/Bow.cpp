#include "Bow.hpp"
#include <iostream> 

Bow::Bow()
{
    std::cout << "Bow created." << std::endl;
}

Bow::~Bow() 
{
    std::cout << "Bow destroyed." << std::endl;
}

std::string Bow::Attack(const std::string& target) const 
{
    return "Shooting an arrow at " + target + " with a bow!";
}