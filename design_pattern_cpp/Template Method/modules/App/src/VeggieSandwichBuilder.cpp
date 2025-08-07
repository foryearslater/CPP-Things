#include "VeggieSandwichBuilder.hpp"

VeggieSandwichBuilder::VeggieSandwichBuilder()
{
    std::cout << "VeggieSandwichBuilder created." << std::endl;
}

VeggieSandwichBuilder::~VeggieSandwichBuilder()
{
    std::cout << "VeggieSandwichBuilder destroyed." << std::endl;
}

void VeggieSandwichBuilder::AddMainIngredient()
{
    std::cout << "Adding a veggie patty." << std::endl;
}

void VeggieSandwichBuilder::AddCondiments()
{
    std::cout << "Adding ketchup and mustard." << std::endl;
}

bool VeggieSandwichBuilder::WantsVegetables() const
{
    return false;
}