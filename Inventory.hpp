#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

#include <map>
#include "Item.hpp"

class Inventory {
    public:
        // Constructor
        Inventory();

        // Parametized Constructor
        // Inventory(const std::string &name, int code = 0, double price = 0.0);

        // Copy Constructor
        Inventory(const Inventory &other);

        // Move Constructor
        Inventory(Inventory &&other) noexcept;

        // Copy Assignement Operator
        Inventory &operator=(const Inventory &other) noexcept;

        // Move Assignement Operator
        Inventory &operator=(Inventory &&other) noexcept;

    private:
        std::unordered_map<int, Item*> items_;
        int size_;
};

#endif 