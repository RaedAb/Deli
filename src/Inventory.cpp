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

// Scan CSV for products with matching barcode
std::shared_ptr<Item> Inventory::queryDatabase(const std::string &barcode)
{
    return nullptr;
}

// Add an Item to the inventory
void Inventory::addItem(const Item &item)
{
    // Create or find the shared_ptr
    auto it = items_.find(item.getCode());
    if (it != items_.end())
    {
        // Update quantity
        it->second->setQuantity(it->second->getQuantity() + item.getQuantity());
    }
    else
    {
        // Add pointer to item
        items_[item.getCode()] = std::make_shared<Item>(item);
    }

    // Update size and value
    size_ += item.getQuantity();
    value_ += item.getPrice() * item.getQuantity();
}

// Remove an Item from the inventory
void Inventory::removeItem(const Item &item)
{
    auto it = items_.find(item.getCode());
    if (it != items_.end())
    {
        if (it->second->getQuantity() > 1)
        {
            it->second->setQuantity(it->second->getQuantity() - item.getQuantity());
        }
    }
    else
    {
        // Item does not exist
    }

    // Update size and value
    size_ -= item.getQuantity();
    value_ -= item.getPrice() * item.getQuantity();
}

/**
 * Set items map
 * @param items a refrence to an items map
 */
void Inventory::setItems(const std::unordered_map<int, std::shared_ptr<Item>> &items)
{
    items_ = items;
    
    // Update size and value
    size_ = items_.size();
    value_ = 0;
    for (const auto &[barcode, item] : items_)
    {
        if (item)
        {
            value_ += item->getPrice();
        }
    }
}

/**
 * @return refrence to items map
 */
const std::unordered_map<int, std::shared_ptr<Item>> &Inventory::getItems() const
{
    return items_;
}

/**
 * Get item by barcode
 * 
 * @return Pointer to Item Object
 */
std::shared_ptr<Item> Inventory::getItem(const int barcode) const
{
    auto it = items_.find(barcode);
    if (it != items_.end())
    {
        return it->second;
    }
    return nullptr;
}

// Get Inventory size
int Inventory::getSize() const
{
    return size_;
}

// Get total value
int Inventory::getValue() const
{
    return value_;
}