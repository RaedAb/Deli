#include <iostream>
#include <iomanip>
#include "../include/Item.hpp"
#include "../include/Sandwich.hpp"
#include "../include/Inventory.hpp"

int main()
{
    Inventory deli;
    std::cout << "Initial Size: " << deli.getSize() << "\n";

    Item* water = new Item("Poland Spring", 1, 123, 1, 0.14);
    Sandwich* blt = new Sandwich("BLT", 123, 4.50);

    std::cout << "Adding two items...\n";

    deli.addItem(water);
    deli.addItem(blt);

    std::cout << "Current Size: " << deli.getSize() << "\n";

    water = nullptr;
    blt = nullptr;

    std::cout << "Current Size: " << deli.getSize() << "\n";

    return 0;
}
