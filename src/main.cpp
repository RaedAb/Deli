#include <iostream>
#include <iomanip>
#include "../include/Item.hpp"
#include "../include/Sandwich.hpp"
#include "../include/Inventory.hpp"

int main()
{
    Item water("Poland Spring", 1, 123, 1, 0.14);

    std::cout << water.getName() << ": $" << std::fixed << std::setprecision(2) << water.getPrice() << std::endl;
    std::cout << "Possible gain: $" << water.getProfit();

    Inventory deli;

    return 0;
}
