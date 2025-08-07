#include <iostream>
#include <memory>

#include "SandwichBuilder.hpp"
#include "ChickenSandwichBuilder.hpp"
#include "VeggieSandwichBuilder.hpp"

int main()
{
    std::cout << "--- Client: Requesting Chicken Sandwich ---" << std::endl;
    std::unique_ptr<SandwichBuilder> chickenSandwich = std::make_unique<ChickenSandwichBuilder>();
    chickenSandwich->MakeSandwich();
    std::cout << std::endl;

    std::cout << "--- Client: Requesting Veggie Sandwich ---" << std::endl;
    std::unique_ptr<SandwichBuilder> veggieSandwich = std::make_unique<VeggieSandwichBuilder>();
    veggieSandwich->MakeSandwich();
    std::cout << std::endl;

    std::cout << "Program finished." << std::endl;

    return 0;
}