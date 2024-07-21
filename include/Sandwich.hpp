#ifndef SANDWICH_HPP_
#define SANDWICH_HPP_

#include "Item.hpp"
#include <vector>

class Sandwich : public Item
{
    public:
        // Constructor
        Sandwich();

        // Parametized Constructor
        Sandwich(const std::string &name, int code = 0, double price = 0.0, const std::vector<Item *> &ingredients = {});

        // Copy Constructor
        Sandwich(const Sandwich &other);

        // Move Constructor
        Sandwich(Sandwich &&other) noexcept;

        // Copy Assignement Operator
        Sandwich &operator=(const Sandwich &other) noexcept;

        // Move Assignement Operator
        Sandwich &operator=(Sandwich &&other) noexcept;

        // Add an ingredient
        bool addIngredient(Item *ingredient);

        // Remove an ingredient
        bool removeIngredient(Item *ingredient);

        // Get vector of ingredients
        std::vector<Item *> getIngredients() const;

        // Override getProfit method
        double getProfit() const override;

    private:
        std::vector<Item *> ingredients_;
};

#endif