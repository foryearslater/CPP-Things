#include "Projector.hpp"


Projector::Projector(const std::string& description) : m_description(description) 
{
    std::cout << m_description << " created." << std::endl;
}


Projector::~Projector() 
{
    std::cout << m_description << " destroyed." << std::endl;
}


void Projector::On() 
{
    std::cout << m_description << " turning on." << std::endl;
}

void Projector::Off() 
{
    std::cout << m_description << " turning off." << std::endl;
}

void Projector::WideScreenMode() 
{
    std::cout << m_description << " setting to widescreen mode (16x9)." << std::endl;
}

void Projector::TvMode() 
{
    std::cout << m_description << " setting to TV mode (4x3)." << std::endl;
}

std::string Projector::GetDescription() const 
{
    return m_description;
}