#include "../include/Sandwich.hpp"

/**
 * @brief Default Constructor
 *
 */
Sandwich::Sandwich() : Item(), ingredients_{}
{
}

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
Sandwich::Sandwich(const std::string &name, int code, double price, const std::vector<Item *> &ingredients)
    : Item(name, 1, code, price), ingredients_{ingredients}
{
}

/**
 * @brief Copy Constructor
 *
 * Creates a new Sandwich as a copy of the provided Sandwich object.
 *
 * @param other Sandwich object to copy from
 */
Sandwich::Sandwich(const Sandwich &other) : Item(other), ingredients_{other.ingredients_}
{
}

/**
 * @brief Move Constructor
 *
 * Transfers ownership of resources from the provided Sandwich to the new Sandwich.
 *
 * @param other Sandwich object to move from
 */
Sandwich::Sandwich(Sandwich &&other) noexcept
    : Item(std::move(other)), ingredients_{std::move(other.ingredients_)}
{
}

/**
 * @brief Copy Assignment Operator
 *
 * Replaces the current Sandwich values with those from another Sandwich object.
 *
 * @param other Sandwich object to copy from
 * @return A reference to this Sandwich object
 */
Sandwich &Sandwich::operator=(const Sandwich &other) noexcept
{
    if (this != &other)
    {
        Item::operator=(other);
        ingredients_ = other.ingredients_;
    }
    return *this;
}

/**
 * @brief Move Assignment Operator
 *
 * Transfers ownership of resources from another Sandwich object to this Sandwich.
 *
 * @param other Sandwich object to move from
 * @return A reference to this Sandwich object
 */
Sandwich &Sandwich::operator=(Sandwich &&other) noexcept
{
    if (this != &other)
    {
        Item::operator=(std::move(other));
        ingredients_ = std::move(other.ingredients_);
        // Clean
        other.ingredients_.clear();
    }
    return *this;
}

/**
 * @brief Add an Ingredient
 *
 * Attempts to add the Item pointer to the list of ingredients.
 *
 * @param ingredient Pointer to the Item to be added
 * @return true if the ingredient was successfully added, otherwise false
 */
bool Sandwich::addIngredient(Item *ingredient)
{
    if (ingredient)
    {
        ingredients_.push_back(ingredient);
    }

    // Recalculate the unit price
    setInitCost(getInitCost() + ingredient->getInitCost());

    return false; // ingredient is nullptr
}

/**
 * @brief Remove an Ingredient
 *
 * Attempts to remove the provided Item pointer from the list of ingredients.
 *
 * @param ingredient Pointer to the Item to be removed
 * @return true if the ingredient was successfully removed, otherwise false
 */
bool Sandwich::removeIngredient(Item *ingredient)
{
    auto it = std::find(ingredients_.begin(), ingredients_.end(), ingredient);
    if (it != ingredients_.end())
    {
        ingredients_.erase(it);
        // Recalculate the unit price
        setInitCost(getInitCost() - ingredient->getInitCost());

        return true;
    }
    return false; // Ingredient could not found
}

/**
 * @brief Get Ingredients
 *
 * Returns the list of ingredients for the Sandwich.
 *
 * @return A vector of pointers to Item objects representing the ingredients
 */
std::vector<Item *> Sandwich::getIngredients() const
{
    return ingredients_;
}

/**
 * @brief Get Profit
 *
 * Calculates the profit of the Sandwich based on its selling price and the costs of its ingredients.
 *
 * @return The profit, calculated as the difference between the price and the total cost of ingredients
 */
double Sandwich::getProfit() const
{
    return getPrice() - getInitCost();
}