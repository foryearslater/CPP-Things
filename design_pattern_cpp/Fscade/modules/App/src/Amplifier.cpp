#include "Amplifier.hpp"

Amplifier::Amplifier(const std::string& description) : m_description(description) 
{
    std::cout << m_description << " created." << std::endl;
}


Amplifier::~Amplifier() 
{
    std::cout << m_description << " destroyed." << std::endl;
}

void Amplifier::On() 
{
    std::cout << m_description << " turning on." << std::endl;
}

void Amplifier::Off() 
{
    std::cout << m_description << " turning off." << std::endl;
}

void Amplifier::SetDvd(DvdPlayer* dvdPlayer) 
{
    if (dvdPlayer) 
    {
        std::cout << m_description << " setting DVD player as input: " << dvdPlayer->GetDescription() << std::endl;
    } 
    else 
    {
        std::cout << m_description << " setting DVD player as input: NULL" << std::endl;
    }
}

void Amplifier::SetVolume(int volume) 
{
    std::cout << m_description << " setting volume to " << volume << "." << std::endl;
}

void Amplifier::SetSurroundSound() 
{
    std::cout << m_description << " setting surround sound." << std::endl;
}

std::string Amplifier::GetDescription() const 
{
    return m_description;
}