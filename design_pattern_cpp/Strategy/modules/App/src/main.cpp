#include <iostream>
#include <memory>
#include "Duck.hpp"
#include "FlyBehavior.hpp"
#include "QuackBehavior.hpp"
#include "FlyWithWings.hpp"
#include "FlyNoWay.hpp"
#include "Quack.hpp"
#include "MuteQuack.hpp"

int main()
{

    std::cout << "--- Creating Mallard Duck ---" << std::endl;
    std::unique_ptr<Duck> mallard = std::make_unique<Duck>(
        std::make_unique<FlyWithWings>(),
        std::make_unique<Quack>(),
        "Mallard Duck");
    mallard->Display();
    mallard->PerformFly();
    mallard->PerformQuack();
    std::cout << std::endl;

    std::cout << "--- Creating Rubber Duck ---" << std::endl;
    std::unique_ptr<Duck> rubberDuck = std::make_unique<Duck>(
        std::make_unique<FlyNoWay>(),
        std::make_unique<MuteQuack>(),
        "Rubber Duck");
    rubberDuck->Display();
    rubberDuck->PerformFly();
    rubberDuck->PerformQuack();
    std::cout << std::endl;

    std::cout << "--- Changing Rubber Duck's Behavior at Runtime ---" << std::endl;
    rubberDuck->SetFlyBehavior(std::make_unique<FlyWithWings>());
    rubberDuck->PerformFly();

    rubberDuck->SetQuackBehavior(std::make_unique<Quack>());
    rubberDuck->PerformQuack();
    std::cout << std::endl;

    std::cout << "Program finished." << std::endl;

    return 0;
}