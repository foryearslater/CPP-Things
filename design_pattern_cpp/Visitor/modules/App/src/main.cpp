#include <iostream>
#include <memory>
#include <iomanip>

#include "ComputerPart.hpp"
#include "ComputerPartVisitor.hpp"
#include "Keyboard.hpp"
#include "Monitor.hpp"
#include "Mouse.hpp"
#include "Computer.hpp"
#include "ComputerPartDisplayVisitor.hpp"
#include "ComputerPartPriceVisitor.hpp"

int main()
{

    std::cout << "--- Building Computer Components ---" << std::endl;
    std::unique_ptr<Computer> computer = std::make_unique<Computer>();
    computer->AddPart(std::make_unique<Keyboard>());
    computer->AddPart(std::make_unique<Monitor>());
    computer->AddPart(std::make_unique<Mouse>());
    std::cout << std::endl;

    std::cout << "--- Using Display Visitor ---" << std::endl;
    std::unique_ptr<ComputerPartDisplayVisitor> displayVisitor =
        std::make_unique<ComputerPartDisplayVisitor>();

    computer->Accept(displayVisitor.get());
    std::cout << std::endl;

    std::cout << "--- Using Price Visitor ---" << std::endl;
    std::unique_ptr<ComputerPartPriceVisitor> priceVisitor =
        std::make_unique<ComputerPartPriceVisitor>();

    computer->Accept(priceVisitor.get());

    std::cout << "Total Computer Price: $" << std::fixed << std::setprecision(2)
              << priceVisitor->GetTotalPrice() << std::endl;
    std::cout << std::endl;

    std::cout << "Program finished." << std::endl;

    return 0;
}