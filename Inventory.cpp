#include "Inventory.hpp"

// Constructor
Inventory::Inventory() : items_({}), size_(0)
{
}

// Copy Constructor
Inventory::Inventory(const Inventory &other) : items_(other.items_), size_(other.size_)
{
}

// Move Constructor
Inventory::Inventory(Inventory &&other) noexcept : items_(std::move(other.items_)), size_(other.size_)
{
}

// Copy Assignement Operator
Inventory &Inventory::operator=(const Inventory &other) noexcept
{
    if (this != &other)
    {
        items_ = other.items_;
        size_ = other.size_;
    }
    return *this;
}

// Move Assignement Operator
Inventory &Inventory::operator=(Inventory &&other) noexcept
{
    if (this != &other)
    {
        items_ = std::move(other.items_);
        size_ = other.size_;
    }
    return *this;
}

// Add an Item to the inventory
void Inventory::addItem(Item *item)
{
    // Check if item exists
    auto it = items_.find(item->getCode());
    if (it != items_.end())
    {
        // Update quantity
        it->second->setQuantity(it->second->getQuantity() + item->getQuantity());
    }
    else
    {
        items_[item->getCode()] = item;
    }
}