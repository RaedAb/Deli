#include "Sandwich.hpp"

// Constructor
Sandwich::Sandwich() : Item(), ingredients_{}
{
}

// Parametized Constructor
Sandwich::Sandwich(const std::string &name, int code, double price, std::vector<Item *> ingredients)
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

    return false; // ingredient is nullptr
}

// Get vector of ingredients
std::vector<Item *> Sandwich::getIngredients() const {
    return ingredients_;
}