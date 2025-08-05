#include <iostream>
#include <memory>
#include "SimpleCoffee.hpp"
#include "ConcreteDecorators.hpp"

int main() 
{
    std::shared_ptr<Coffee> myCoffee = std::make_shared<SimpleCoffee>();
    std::cout << "Order 1:" << std::endl;
    std::cout << "  Description: " << myCoffee->GetDescription() << std::endl;
    std::cout << "  Cost: " << myCoffee->GetCost() << std::endl;

    myCoffee = std::make_shared<MilkDecorator>(myCoffee);
    std::cout << "\nOrder 2 (added Milk):" << std::endl;
    std::cout << "  Description: " << myCoffee->GetDescription() << std::endl;
    std::cout << "  Cost: " << myCoffee->GetCost() << std::endl;

    myCoffee = std::make_shared<SugarDecorator>(myCoffee);
    std::cout << "\nOrder 3 (added Sugar):" << std::endl;
    std::cout << "  Description: " << myCoffee->GetDescription() << std::endl;
    std::cout << "  Cost: " << myCoffee->GetCost() << std::endl;

    myCoffee = std::make_shared<SugarDecorator>(myCoffee);
    std::cout << "\nOrder 4 (added one more Sugar):" << std::endl;
    std::cout << "  Description: " << myCoffee->GetDescription() << std::endl;
    std::cout << "  Cost: " << myCoffee->GetCost() << std::endl;

    std::shared_ptr<Coffee> anotherCoffee = std::make_shared<SimpleCoffee>();
    anotherCoffee = std::make_shared<SugarDecorator>(anotherCoffee);
    std::cout << "\nAnother Order:" << std::endl;
    std::cout << "  Description: " << anotherCoffee->GetDescription() << std::endl;
    std::cout << "  Cost: " << anotherCoffee->GetCost() << std::endl;

    return 0;
}