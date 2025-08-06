#include "Light.hpp"

Light::Light(const std::string& location) : m_location(location) 
{
    std::cout << m_location << " Light created." << std::endl;
}

Light::~Light() 
{
    std::cout << m_location << " Light destroyed." << std::endl;
}

void Light::On() 
{
    std::cout << m_location << " Light is ON." << std::endl;
}

void Light::Off() 
{
    std::cout << m_location << " Light is OFF." << std::endl;
}