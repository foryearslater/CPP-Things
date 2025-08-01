#include <iostream>
#include "MonsterFactory.hpp"

int main() 
{

    MonsterFactory factory;

    std::unique_ptr<Monster> slime1 = factory.CreateMonster(MonsterType::SLIME);
    slime1->Display();

    std::unique_ptr<Monster> slime2 = factory.CreateMonster(MonsterType::SLIME);
    slime2->Display();

    std::unique_ptr<Monster> dragon1 = factory.CreateMonster(MonsterType::DRAGON);
    dragon1->Display();

    if (slime1.get() != slime2.get()) 
    {
        std::cout << "\nslime1 and slime2 are two different objects." << std::endl;
    }

    return 0;
}