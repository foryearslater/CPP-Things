#include "ChickenSandwichBuilder.hpp"

ChickenSandwichBuilder::ChickenSandwichBuilder()
{
    std::cout << "ChickenSandwichBuilder created." << std::endl;
}

ChickenSandwichBuilder::~ChickenSandwichBuilder()
{
    std::cout << "ChickenSandwichBuilder destroyed." << std::endl;
}

void ChickenSandwichBuilder::AddMainIngredient()
{
    std::cout << "Adding grilled chicken slices." << std::endl;
}

void ChickenSandwichBuilder::AddCondiments()
{
    std::cout << "Adding mayonnaise." << std::endl;
}