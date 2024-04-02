#include <iostream>
#include <iomanip>
#include "Item.hpp"
#include "Sandwich.hpp"

int main()
{
    Item water("Poland Spring", 000, 1, 0.14);

    std::cout << water.getName() << ": $" << std::fixed << std::setprecision(2) << water.getPrice() << std::endl;
    std::cout << "Possible gain: $" << water.getProfit();

    return 0;
}
