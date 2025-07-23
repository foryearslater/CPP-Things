#include "Weapon.hpp"
#include "Sword.hpp"
#include "Bow.hpp"
#include "WeaponFactory.hpp"

int main() {
    Weapon* mySword = WeaponFactory::createWeapon("sword");
    if (mySword) 
    {
        mySword->use();
    }

    std::cout << "\n------------------\n" << std::endl;

    Weapon* myBow = WeaponFactory::createWeapon("bow");
    if (myBow) 
    {
        myBow->use();
    }

    std::cout << "\n------------------\n" << std::endl;

    Weapon* unknownWeapon = WeaponFactory::createWeapon("axe");
    if (unknownWeapon) 
    {
        unknownWeapon->use();
    }

    delete mySword;
    delete myBow;

    return 0;
}