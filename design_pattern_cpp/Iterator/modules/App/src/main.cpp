#include <iostream>
#include <memory>

#include "MenuItem.hpp"
#include "Iterator.hpp"
#include "Menu.hpp"
#include "DinerMenu.hpp"
#include "MenuItemIterator.hpp"

class Waitress
{
public:
    explicit Waitress(Menu *dinerMenu) : m_dinerMenu(dinerMenu)
    {
        std::cout << "Waitress created." << std::endl;
    }

    ~Waitress()
    {
        std::cout << "Waitress destroyed." << std::endl;
    }

    void PrintMenu()
    {
        std::cout << "\n--- Printing Diner Menu ---" << std::endl;

        std::unique_ptr<Iterator> dinerIterator = m_dinerMenu->CreateIterator();

        PrintMenuItems(dinerIterator.get());

        std::cout << "--- Menu Printed ---" << std::endl;
    }

private:
    Menu *m_dinerMenu;

    void PrintMenuItems(Iterator *iterator)
    {
        while (iterator->HasNext())
        {
            const MenuItem &menuItem = iterator->Next();
            std::cout << menuItem.ToString() << std::endl;
        }
    }
};

int main()
{

    std::unique_ptr<DinerMenu> dinerMenu = std::make_unique<DinerMenu>();

    Waitress waitress(dinerMenu.get());

    waitress.PrintMenu();

    std::cout << "\nProgram finished." << std::endl;

    return 0;
}