#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <string>

class Item
{
public:
    /**
     * @brief Default Constructor
     *
     * Constructs an Item with name: "n/a", # = 0, code = 0, price = 0.0, p_price = 0
     */
    Item();

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
    Item(const std::string &name, int quantity = 0, int code = 0, double price = 0.0, double init_cost = 0.0);

    /**
     * @brief Copy Constructor
     *
     * Constructs an Item object as a copy of another Item object.
     *
     * @param other The Item object to copy from.
     */
    Item(const Item &other);

    /**
     * @brief Move Constructor
     *
     * Constructs an Item object by transferring resources from another Item object.
     *
     * @param other The Item object to move from.
     */
    Item(Item &&other) noexcept;

    /**
     * @brief Copy Assignment Operator
     *
     * Assigns the state of one Item object to another Item object.
     *
     * @param other The Item object to copy from.
     * @return Reference to this Item object.
     */
    Item &operator=(const Item &other) noexcept;

    /**
     * @brief Move Assignment Operator
     *
     * Moves the state from one Item object to another Item object.
     *
     * @param other The Item object to move from.
     * @return Reference to this Item object.
     */
    Item &operator=(Item &&other) noexcept;

    /**
     * @brief Set Item Name
     *
     * Sets the name of the item.
     *
     * @param name The new name of the item.
     */
    void setName(const std::string &name);

    /**
     * @brief Get Item Name
     *
     * Retrieves the name of the item.
     *
     * @return The name of the item.
     */
    std::string getName() const;

    /**
     * @brief Set Item Quantity
     *
     * Sets the quantity of the item.
     *
     * @param quantity The new quantity of the item.
     */
    void setQuantity(int quantity);

    /**
     * @brief Get Item Quantity
     *
     * Retrieves the quantity of the item.
     *
     * @return The quantity of the item.
     */
    int getQuantity() const;

    /**
     * @brief Set Item Code
     *
     * Sets the unique code of the item.
     *
     * @param code The new unique code of the item.
     */
    void setCode(int code);

    /**
     * @brief Get Item Code
     *
     * Retrieves the unique code of the item.
     *
     * @return The unique code of the item.
     */
    int getCode() const;

    /**
     * @brief Set Item Price
     *
     * Sets the selling price of the item.
     *
     * @param price The new selling price of the item.
     */
    void setPrice(double price);

    /**
     * @brief Get Item Price
     *
     * Retrieves the selling price of the item.
     *
     * @return The selling price of the item.
     */
    double getPrice() const;

    /**
     * @brief Set Purchase Price
     *
     * Sets the initial cost price of the item.
     *
     * @param init_cost The new initial cost price of the item.
     */
    void setInitCost(double init_cost);

    /**
     * @brief Get Purchase Price
     *
     * Retrieves the initial cost price of the item.
     *
     * @return The initial cost price of the item.
     */
    double getInitCost() const;

    /**
     * @brief Calculate Item Profit
     *
     * Computes the profit made on the item by subtracting the initial cost from the selling price.
     *
     * @return The profit made on the item.
     */
    double getProfit() const;

private:
    std::string name_; ///< Name of the item
    int quantity_;     ///< Quantity of the item
    int code_;         ///< Unique code of the item
    double price_;     ///< Selling price of the item
    double init_cost_; ///< Initial cost price of the item
};

#endif // ITEM_HPP_