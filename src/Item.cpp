#include "../include/Item.hpp"

/**
 * @brief Default Constructor
 *
 * Constructs an Item with name: "n/a", # = 0, code = 0, price = 0.0, p_price = 0
 */
Item::Item() : name_("n/a"), quantity_(0), code_(0), price_(0.0), init_cost_(0.0)
{
}

/**
 * @brief Parameterized Constructor
 *
 * Constructs an Item object with the specified values.
 *
 * @param name The name of the item.
 * @param quantity The quantity of the item.
 * @param code The unique code of the item.
 * @param price The selling price of the item.
 * @param init_cost The initial cost price of the item.
 */
Item::Item(const std::string &name, int quantity, int code, double price, double init_cost)
    : name_(name), quantity_(quantity), code_(code), price_(price), init_cost_(init_cost)
{
}

/**
 * @brief Copy Constructor
 *
 * Constructs an Item object as a copy of another Item object.
 *
 * @param other The Item object to copy from.
 */
Item::Item(const Item &other)
    : name_(other.name_), quantity_(other.quantity_), code_(other.code_), price_(other.price_), init_cost_(other.init_cost_)
{
}

/**
 * @brief Move Constructor
 *
 * Constructs an Item object by transferring resources from another Item object.
 *
 * @param other The Item object to move from.
 */
Item::Item(Item &&other) noexcept
    : name_(std::move(other.name_)), quantity_(other.quantity_), code_(other.code_), price_(other.price_), init_cost_(other.init_cost_)
{
}

/**
 * @brief Copy Assignment Operator
 *
 * Assigns the state of one Item object to another Item object.
 *
 * @param other The Item object to copy from.
 * @return Reference to this Item object.
 */
Item &Item::operator=(const Item &other) noexcept
{
    if (this != &other)
    {
        name_ = other.name_;
        quantity_ = other.quantity_;
        code_ = other.code_;
        price_ = other.price_;
        init_cost_ = other.init_cost_;
    }

    return *this;
}

/**
 * @brief Move Assignment Operator
 *
 * Moves the state from one Item object to another Item object.
 *
 * @param other The Item object to move from.
 * @return Reference to this Item object.
 */
Item &Item::operator=(Item &&other) noexcept
{
    if (this != &other)
    {
        name_ = std::move(other.name_);
        quantity_ = other.quantity_;
        code_ = other.code_;
        price_ = other.price_;
        init_cost_ = other.init_cost_;
    }

    return *this;
}

/**
 * @brief Set Item Name
 *
 * Sets the name of the item.
 *
 * @param name The new name of the item.
 */
void Item::setName(const std::string &name)
{
    name_ = (!name.length() ? "n/a" : name);
}

/**
 * @brief Get Item Name
 *
 * Retrieves the name of the item.
 *
 * @return The name of the item.
 */
std::string Item::getName() const
{
    return name_;
}

/**
 * @brief Set Item Quantity
 *
 * Sets the quantity of the item.
 *
 * @param quantity The new quantity of the item.
 */
void Item::setQuantity(int quantity)
{
    quantity_ = quantity;
}

/**
 * @brief Get Item Quantity
 *
 * Retrieves the quantity of the item.
 *
 * @return The quantity of the item.
 */
int Item::getQuantity() const
{
    return quantity_;
}

/**
 * @brief Set Item Code
 *
 * Sets the unique code of the item.
 *
 * @param code The new unique code of the item.
 */
void Item::setCode(int code)
{
    code_ = (code < 0) ? 0 : code;
}

/**
 * @brief Get Item Code
 *
 * Retrieves the unique code of the item.
 *
 * @return The unique code of the item.
 */
int Item::getCode() const
{
    return code_;
}

/**
 * @brief Set Item Price
 *
 * Sets the selling price of the item.
 *
 * @param price The new selling price of the item.
 */
void Item::setPrice(double price)
{
    price_ = (price < 0.0 ? 0.0 : price);
}

/**
 * @brief Get Item Price
 *
 * Retrieves the selling price of the item.
 *
 * @return The selling price of the item.
 */
double Item::getPrice() const
{
    return price_;
}

/**
 * @brief Set Purchase Price
 *
 * Sets the initial cost price of the item.
 *
 * @param init_cost The new initial cost price of the item.
 */
void Item::setInitCost(double init_cost)
{
    init_cost_ = (init_cost < 0 ? 0 : init_cost);
}

/**
 * @brief Get Purchase Price
 *
 * Retrieves the initial cost price of the item.
 *
 * @return The initial cost price of the item.
 */
double Item::getInitCost() const
{
    return init_cost_;
}

/**
 * @brief Calculate Item Profit
 *
 * Computes the profit made on the item by subtracting the initial cost from the selling price.
 *
 * @return The profit made on the item.
 */
double Item::getProfit() const
{
    return price_ - init_cost_;
}