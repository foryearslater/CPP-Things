#include "CharacterDirector.hpp"

void CharacterDirector::SetBuilder(std::shared_ptr<CharacterBuilder> builder) 
{
    m_builder = builder;
}

std::shared_ptr<Character> CharacterDirector::GetCharacter() 
{
    return m_builder->GetCharacter();
}

void CharacterDirector::ConstructCharacter() 
{
    if (!m_builder) return;
    
    m_builder->CreateNewCharacter();
    m_builder->BuildWeapon();
    m_builder->BuildArmor();
    m_builder->BuildSkill();
}