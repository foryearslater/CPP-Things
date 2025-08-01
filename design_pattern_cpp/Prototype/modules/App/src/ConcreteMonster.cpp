#include "ConcreteMonster.hpp"



Slime::Slime(const std::string& name, int health) 
{
    m_name = name;
    m_health = health;
}

std::unique_ptr<Monster> Slime::Clone() const 
{
    return std::make_unique<Slime>(*this);
}

void Slime::Display() const 
{
    std::cout << "Slime '" << m_name << "' with " << m_health << " HP." << std::endl;
}


Dragon::Dragon(const std::string& name, int health, int fire_intensity) 
{
    m_name = name;
    m_health = health;
    m_fire_intensity = fire_intensity;
}

std::unique_ptr<Monster> Dragon::Clone() const 
{
    return std::make_unique<Dragon>(*this);
}

void Dragon::Display() const 
{
    std::cout << "Dragon '" << m_name << "' with " << m_health << " HP and Fire Intensity " << m_fire_intensity << "." << std::endl;
}