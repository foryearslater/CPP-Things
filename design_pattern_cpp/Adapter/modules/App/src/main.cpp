#include <iostream>
#include <memory> 

#include "IWeapon.hpp"
#include "Bow.hpp"
#include "OldSword.hpp"
#include "OldSwordAdapter.hpp"


void ClientCode(const IWeapon* weapon) 
{
    if (weapon) 
    {
        std::cout << "Client: I'm using a weapon now." << std::endl;
        std::cout << weapon->Attack("Goblin") << std::endl;
    } 
    else 
    {
        std::cout << "Client: No weapon provided." << std::endl;
    }
    std::cout << std::endl;
}


int main() 
{
    std::unique_ptr<IWeapon> myBow = std::make_unique<Bow>();

    ClientCode(myBow.get());

    std::unique_ptr<OldSword> oldSwordObject = std::make_unique<OldSword>();

    std::unique_ptr<IWeapon> adaptedSword = std::make_unique<OldSwordAdapter>(oldSwordObject.get());
    
    ClientCode(adaptedSword.get());

    return 0;
}