#include "OldSwordAdapter.hpp"
#include <iostream> 


OldSwordAdapter::OldSwordAdapter(OldSword* oldSword) : m_oldSword(oldSword) 
{
    std::cout << "OldSwordAdapter created, adapting an OldSword." << std::endl;
}


OldSwordAdapter::~OldSwordAdapter() 
{
    std::cout << "OldSwordAdapter destroyed." << std::endl;
}

std::string OldSwordAdapter::Attack(const std::string& target) const 
{
    if (m_oldSword)
    {
        return m_oldSword->Swing(target);
    }
    return "Adapter is missing OldSword object!";
}