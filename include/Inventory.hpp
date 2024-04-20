#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

#include <map>
#include "Item.hpp"

class Inventory
{
    public:
        // Constructor
        Inventory();

        // Copy Constructor
        Inventory(const Inventory &other);

        // Move Constructor
        Inventory(Inventory &&other) noexcept;

        // Copy Assignement Operator
        Inventory &operator=(const Inventory &other) noexcept;

        // Move Assignement Operator
        Inventory &operator=(Inventory &&other) noexcept;

        // Scan CSV for products with matching barcode
        Item* queryDatabase(const std::string& barcode);

        // Add an Item to the inventory
        void addItem(Item* item);

        // Remove an Item from the inventory
        void removeItem(Item* item);

        // Get Inventory size
        int getSize() const;

    private:
        std::unordered_map<int, Item *> items_;
        double value_;
        int size_;

};

#endif