#include <iostream>
#include <iomanip>
#include "Item.hpp"

int main()
{
    Item sandwich("BLT", 123, 4.50);

    std::cout << sandwich.getName() << ": $" << std::fixed << std::setprecision(2) << sandwich.getPrice() << std::endl;
    return 0;
}
