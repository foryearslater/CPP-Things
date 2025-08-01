#include "ConcreteBuilder.hpp"


void WarriorBuilder::BuildWeapon() 
{
    m_character->SetWeapon("Greatsword");
}

void WarriorBuilder::BuildArmor() 
{
    m_character->SetArmor("Plate Armor");
}

void WarriorBuilder::BuildSkill() 
{
    m_character->SetSkill("Charge");
}

void MageBuilder::BuildWeapon() 
{
    m_character->SetWeapon("Staff of Fire");
}

void MageBuilder::BuildArmor() 
{
    m_character->SetArmor("Cloth Robe");
}

void MageBuilder::BuildSkill() 
{
    m_character->SetSkill("Fireball");
}