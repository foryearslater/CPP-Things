#include "MonsterFactory.hpp"
#include "ConcreteMonster.hpp"

MonsterFactory::MonsterFactory() 
{
    m_prototypes[MonsterType::SLIME] = std::make_unique<Slime>("Green Slime", 50);
    m_prototypes[MonsterType::DRAGON] = std::make_unique<Dragon>("Red Dragon", 500, 99);
}

std::unique_ptr<Monster> MonsterFactory::CreateMonster(MonsterType type) 
{
    return m_prototypes[type]->Clone();
}