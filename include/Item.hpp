#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <string>

class Item
{
    public:
        // Constructor
        Item();

        // Parametized Constructor
        Item(const std::string &name, int quantity = 0, int code = 0, double price = 0.0, double init_cost = 0.0);

        // Copy Constructor
        Item(const Item &other);

        // Move Constructor
        Item(Item &&other) noexcept;

        // Copy Assignement Operator
        Item &operator=(const Item &other) noexcept;

        // Move Assignement Operator
        Item &operator=(Item &&other) noexcept;

        // Set Item name
        void setName(const std::string &name);

        // Get Item Name
        std::string getName() const;

        // Set item quantity
        void setQuantity(int quantity);

        // Get item Quantity
        int getQuantity() const;

        // Set Item Barcode
        void setCode(int code);

        // Get Item Barcode
        int getCode() const;

        // Set Item Price
        void setPrice(double price);

        // Get an Item price
        double getPrice() const;

        // Set Purchase Price
        void setInitCost(double init_cost);

        // Get Purchase Price
        double getInitCost() const;

        // Items profit
        virtual double getProfit() const;

    private:
        std::string name_;
        int quantity_;
        int code_;
        double price_;
        double init_cost_;
};

#endif