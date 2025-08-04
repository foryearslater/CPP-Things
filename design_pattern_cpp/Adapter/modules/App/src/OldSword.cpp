#include "OldSword.hpp"
#include <iostream> 


OldSword::OldSword() 
{
    std::cout << "OldSword created." << std::endl;
}

OldSword::~OldSword() 
{
    std::cout << "OldSword destroyed." << std::endl;
}

std::string OldSword::Swing(const std::string& enemy) const 
{
    return "Swinging the old sword at " + enemy + "!";
}