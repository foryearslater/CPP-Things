#include "Character.hpp"

void Character::SetWeapon(const std::string& weapon) 
{
    m_weapon = weapon;
}

void Character::SetArmor(const std::string& armor) 
{
    m_armor = armor;
}

void Character::SetSkill(const std::string& skill) 
{
    m_skill = skill;
}

void Character::Display() const 
{
    std::cout << "Character Configuration:" << std::endl;
    std::cout << "  Weapon: " << (m_weapon.empty() ? "None" : m_weapon) << std::endl;
    std::cout << "  Armor:  " << (m_armor.empty() ? "None" : m_armor) << std::endl;
    std::cout << "  Skill:  " << (m_skill.empty() ? "None" : m_skill) << std::endl;
}