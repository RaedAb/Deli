#include "../include/Sandwich.hpp"

// Constructor
Sandwich::Sandwich() : Item(), ingredients_{}
{
}

// Parametized Constructor
Sandwich::Sandwich(const std::string &name, int code, double price, const std::vector<Item *> &ingredients)
    : Item(name, code, price), ingredients_{ingredients}
{
}

// Copy Constructor
Sandwich::Sandwich(const Sandwich &other) : Item(other), ingredients_{other.ingredients_}
{
}

// Move Constructor
Sandwich::Sandwich(Sandwich &&other) noexcept
    : Item(std::move(other)), ingredients_{std::move(other.ingredients_)}
{
}

// Copy Assignement Operator
Sandwich &Sandwich::operator=(const Sandwich &other) noexcept
{
    if (this != &other)
    {
        Item::operator=(other);
        ingredients_ = other.ingredients_;
    }
    return *this;
}

// Move Assignement Operator
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

// Add an ingredient
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

// Remove an ingredient
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

// Get vector of ingredients
std::vector<Item *> Sandwich::getIngredients() const
{
    return ingredients_;
}

// Override getProfit method
double Sandwich::getProfit() const
{
    return getPrice() - getInitCost();
}