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
    std::shared_ptr<Item> queryDatabase(const std::string &barcode);

    // Add an Item to the inventory
    void addItem(const Item &item);

    // Remove an Item from the inventory
    void removeItem(const Item &item);

    /**
     * Set items map
     * @param items a refrence to an items map
    */
    void setItems(const std::unordered_map<int, std::shared_ptr<Item>> &items);

    /**
     * @return refrence to items map
    */
    const std::unordered_map<int, std::shared_ptr<Item>> &getItems() const;

    /**
     * @return Pointer to Item Object
    */
    std::shared_ptr<Item> getItem(const int barcode) const;

    // Get Inventory size
    int getSize() const;

    // Get total value
    int getValue() const;

private:
    std::unordered_map<int, std::shared_ptr<Item>> items_;
    double value_;
    int size_;
};

#endif