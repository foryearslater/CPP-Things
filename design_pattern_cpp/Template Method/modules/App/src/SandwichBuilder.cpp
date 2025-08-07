#include "SandwichBuilder.hpp"

void SandwichBuilder::MakeSandwich()
{
    std::cout << "\n--- Starting to make a sandwich ---" << std::endl;
    PrepareBread();
    AddMainIngredient();
    AddCondiments();

    if (WantsVegetables())
    {
        AddVegetables();
    }
    else
    {
        std::cout << "Skipping vegetables." << std::endl;
    }

    WrapSandwich();
    std::cout << "--- Sandwich finished! ---" << std::endl;
}

void SandwichBuilder::PrepareBread() const
{
    std::cout << "Preparing bread (slice and toast)." << std::endl;
}

void SandwichBuilder::AddVegetables() const
{
    std::cout << "Adding lettuce, tomato, and onions." << std::endl;
}

void SandwichBuilder::WrapSandwich() const
{
    std::cout << "Wrapping sandwich nicely." << std::endl;
}