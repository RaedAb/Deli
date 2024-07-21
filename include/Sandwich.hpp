#ifndef SANDWICH_HPP_
#define SANDWICH_HPP_

#include "Item.hpp"
#include <vector>

class Sandwich : public Item
{
public:
    /**
     * @brief Default Constructor
     *
     */
    Sandwich();

    /**
     * @brief Parameterized Constructor
     *
     * Initializes a Sandwich with the provided values.
     *
     * @param name Name of the sandwich
     * @param code Code for identifying the sandwich (default is 0)
     * @param price Selling price of the sandwich (default is 0.0)
     * @param ingredients List of ingredients (default is empty vector)
     */
    Sandwich(const std::string &name, int code = 0, double price = 0.0, const std::vector<Item *> &ingredients = {});

    /**
     * @brief Copy Constructor
     *
     * Creates a new Sandwich as a copy of the provided Sandwich object.
     *
     * @param other Sandwich object to copy from
     */
    Sandwich(const Sandwich &other);

    /**
     * @brief Move Constructor
     *
     * Transfers ownership of resources from the provided Sandwich to the new Sandwich.
     *
     * @param other Sandwich object to move from
     */
    Sandwich(Sandwich &&other) noexcept;

    /**
     * @brief Copy Assignment Operator
     *
     * Replaces the current Sandwich values with those from another Sandwich object.
     *
     * @param other Sandwich object to copy from
     * @return A reference to this Sandwich object
     */
    Sandwich &operator=(const Sandwich &other) noexcept;

    /**
     * @brief Move Assignment Operator
     *
     * Transfers ownership of resources from another Sandwich object to this Sandwich.
     *
     * @param other Sandwich object to move from
     * @return A reference to this Sandwich object
     */
    Sandwich &operator=(Sandwich &&other) noexcept;

    /**
     * @brief Add an Ingredient
     *
     * Attempts to add the provided Item pointer to the list of ingredients.
     *
     * @param ingredient Pointer to the Item to be added
     * @return true if the ingredient was successfully added, otherwise false
     */
    bool addIngredient(Item *ingredient);

    /**
     * @brief Remove an Ingredient
     *
     * Attempts to remove the provided Item pointer from the list of ingredients.
     *
     * @param ingredient Pointer to the Item to be removed
     * @return true if the ingredient was successfully removed, otherwise false
     */
    bool removeIngredient(Item *ingredient);

    /**
     * @brief Get Ingredients
     *
     * Returns the list of ingredients for the Sandwich.
     *
     * @return A vector of pointers to Item objects representing the ingredients
     */
    std::vector<Item *> getIngredients() const;

    /**
     * @brief Get Profit
     *
     * Calculates the profit of the Sandwich based on its selling price and the costs of its ingredients.
     *
     * @return The profit, calculated as the difference between the price and the total cost of ingredients
     */
    double getProfit() const;

private:
    // List of ingredients that make up the Sandwich
    // Each Item pointer in this vector represents an ingredient used in the Sandwich.
    std::vector<Item *> ingredients_;
};

#endif
