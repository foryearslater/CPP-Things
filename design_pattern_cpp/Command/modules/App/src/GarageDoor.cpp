#include "GarageDoor.hpp"

GarageDoor::GarageDoor(const std::string& location) : m_location(location) 
{
    std::cout << m_location << " Garage Door created." << std::endl;
}

GarageDoor::~GarageDoor() 
{
    std::cout << m_location << " Garage Door destroyed." << std::endl;
}

void GarageDoor::Up() 
{
    std::cout << m_location << " Garage Door is Open." << std::endl;
}

void GarageDoor::Down() 
{
    std::cout << m_location << " Garage Door is Closed." << std::endl;
}

void GarageDoor::Stop() 
{
    std::cout << m_location << " Garage Door is Stopped." << std::endl;
}

void GarageDoor::LightOn() 
{
    std::cout << m_location << " Garage Light is ON." << std::endl;
}

void GarageDoor::LightOff() 
{
    std::cout << m_location << " Garage Light is OFF." << std::endl;
}