#include "Item.hpp"

// Constructor
Item::Item() : name_("n/a"), code_(0), price_(0.0)
{
}

// Parametized Constructor
Item::Item(const std::string& name, int code, double price)
    : name_(name), code_(code), price_(price)
{
}

// Copy Constructor
Item::Item(const Item &other) : name_(other.name_), code_(other.code_), price_(other.price_)
{
}

// Move Constructor
Item::Item(Item &&other) noexcept
    : name_(std::move(other.name_)), code_(other.code_), price_(other.price_)
{
}

// Copy Assignement Operator
Item& Item::operator=(const Item &other) noexcept
{
    if (this != &other) {
        name_ = other.name_;
        code_ = other.code_;
        price_ = other.price_;
    }

    return *this;
}

// Move Assignement Operator
Item& Item::operator=(Item &&other) noexcept
{
    if (this != &other)
    {
        name_ = std::move(other.name_);
        code_ = other.code_;
        price_ = other.price_;
    }

    return *this;
}

// Set Item name
void Item::setName(const std::string &name)
{
    name_ = (!name.length() ? "n/a" : name);
}

// Get Item Name
std::string Item::getName() const
{
    return name_;
}

// Set Item Barcode
void Item::setCode(int code)
{
    code_ = (code < 0) ? 0 : code;
}

// Get Item Barcode
int Item::getCode() const
{
    return code_;
}

// Set Item Price
void Item::setPrice(double price)
{
    price_ = (price < 0) ? 0 : price;
}

// Get an Item price
double Item::getPrice() const
{
    return price_;
}