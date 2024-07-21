#include "../include/Inventory.hpp"

// Constructor
Inventory::Inventory() : items_({}), value_(0), size_(0)
{
}

// Copy Constructor
Inventory::Inventory(const Inventory &other) : items_(other.items_), value_(other.value_), size_(other.size_)
{
}

// Move Constructor
Inventory::Inventory(Inventory &&other) noexcept : items_(std::move(other.items_)), value_(other.value_), size_(other.size_)
{
}

// Copy Assignement Operator
Inventory &Inventory::operator=(const Inventory &other) noexcept
{
    if (this != &other)
    {
        items_ = other.items_;
        value_ = other.value_;
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
        value_ = other.value_;
        size_ = other.size_;
    }
    return *this;
}

// Add an Item to the inventory
void Inventory::addItem(std::shared_ptr<Item> item)
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

    //Update size and value
    size_ += item->getQuantity();
    value_ += item->getPrice() * item->getQuantity();
}

// Remove an Item from the inventory
void Inventory::removeItem(std::shared_ptr<Item> item)
{
    auto it = items_.find(item->getCode());
    if (it != items_.end())
    {
        if (it->second->getQuantity() > 1)
        {
            it->second->setQuantity(it->second->getQuantity() - 1);
        }
    } else {
        // throw exeption item does not exist
    }

    // Update size and value
    size_ --;
    value_ -= item->getPrice();
}

// Get Inventory size
int Inventory::getSize() const
{
    return size_;
}