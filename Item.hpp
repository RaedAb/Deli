#ifndef ITEM_HPP_
#define ITEM_HPP_
#include <string>

class Item
{
    public:
        // Constructor
        Item();

        // Parametized Constructor
        Item(const std::string& name, int code = 0, double price = 0.0);

        // Copy Constructor
        Item(const Item& other);

        // Move Constructor
        Item(Item&& other) noexcept;

        // Copy Assignement Operator
        Item& operator=(const Item& other) noexcept;

        // Move Assignement Operator
        Item& operator=(Item&& other) noexcept;

        // Set Item name
        void setName(const std::string& name);

        // Get Item Name
        std::string getName() const;

        // Set Item Barcode
        void setCode(int code);

        // Get Item Barcode
        int getCode() const;

        // Set Item Price
        void setPrice(double price);

        // Get an Item price
        double getPrice() const;

    private:
        std::string name_;
        int code_;
        double price_;
};

#endif