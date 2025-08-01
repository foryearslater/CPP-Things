#include <iostream>
#include "CharacterDirector.hpp"
#include "ConcreteBuilder.hpp"

int main() 
{
    CharacterDirector director;
    auto warriorBuilder = std::make_shared<WarriorBuilder>();
    auto mageBuilder = std::make_shared<MageBuilder>();

    director.SetBuilder(warriorBuilder);
    director.ConstructCharacter();
    std::shared_ptr<Character> warrior = director.GetCharacter();
    warrior->Display();
    std::cout << std::endl;

    director.SetBuilder(mageBuilder);
    director.ConstructCharacter();
    std::shared_ptr<Character> mage = director.GetCharacter();
    mage->Display();
    std::cout << std::endl;

    warriorBuilder->CreateNewCharacter();
    warriorBuilder->BuildWeapon();
    warriorBuilder->BuildArmor();

    std::shared_ptr<Character> customWarrior = warriorBuilder->GetCharacter();
    customWarrior->Display();

    return 0;
}