#include "../include/Database.hpp"
#include "../include/Inventory.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

/**
 * @brief Param Constructor
 *
 * Initializes a Database object.
 * Adds a product csv file if it does not already exist
 */
Database::Database(const std::string &filename)
{
    std::filesystem::path directoryPath = "./data";
    std::filesystem::path filePath = directoryPath / filename;

    // Ensure directory exists
    if (!std::filesystem::exists(directoryPath))
    {
        if (!std::filesystem::create_directory(directoryPath))
        {
            std::cerr << "Failed to create directory: " + directoryPath.string();
        }
    }

    // Create file if it does not exist
    if (!std::filesystem::exists(filePath))
    {
        std::ofstream file(filePath);
        if (file.is_open())
        {
            file.close();
        }
        else
        {
            std::cerr << "Failed to create file: " + directoryPath.string();
        }
    }
}

/**
 * @brief Convert Item to CSV Format
 *
 * Converts an Item object to a CSV formatted string.
 *
 * @param item Pointer to the Item object
 * @return CSV formatted string
 */
std::string Database::itemToCSV(const std::shared_ptr<Item> item) const
{
    if (item)
    {
        return item->getName() + "," + std::to_string(item->getCode()) + "," + std::to_string(item->getQuantity()) + "," + std::to_string(item->getPrice());
        +"," + std::to_string(item->getInitCost());
    }

    return "";
}

/**
 * @brief Parse CSV Line to Item
 *
 * Parses a CSV formatted string to create an Item object.
 *
 * @param csvLine CSV formatted string
 * @return Pointer to the Item object
 */
std::shared_ptr<Item> Database::parseCSVLine(const std::string &csvLine) const
{
    std::stringstream ss(csvLine);
    std::string name;
    int code;
    int quantity;
    double price;
    double initPrice;

    std::getline(ss, name, ',');

    std::string codeStr, quantityStr, priceStr, initPriceStr;
    std::getline(ss, codeStr, ',');
    std::getline(ss, quantityStr, ',');
    std::getline(ss, priceStr, ',');
    std::getline(ss, initPriceStr, ',');

    if (!codeStr.empty())
        code = std::stoi(codeStr);

    if (!quantityStr.empty())
        quantity = std::stoi(quantityStr);

    if (!priceStr.empty())
        price = std::stod(priceStr);

    if (!initPriceStr.empty())
        initPrice = std::stod(initPriceStr);

    return std::make_shared<Item>(name, quantity, code, price, initPrice);
}

// public

/**
 * @brief Save Inventory to CSV
 *
 * Saves the provided inventory of items to a CSV file.
 *
 * @param inventory Inventory Object
 * @param filename Name of the CSV file
 * @return true if the save operation was successful, otherwise false
 */
bool Database::saveToCSV(const Inventory &inventory, const std::string &filename) const
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        // Header
        file << "Name,Code,Quantity,Price,PurchasePrice\n";
        const auto &items = inventory.getItems();

        // Add each to file
        for (const auto &pair : items)
        {
            if (pair.second)
                file << itemToCSV(pair.second);
        }

        file.close();
        return 1;
    }
    else
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return 0;
    }
}

/**
 * @brief Load Inventory from CSV
 *
 * Loads items from a CSV file into a vector.
 *
 * @param filename Name of the CSV file
 * @return Vector of pointers to Item objects
 */
std::unordered_map<int, std::shared_ptr<Item>> Database::loadFromCSV(const std::string &filename) const
{
    std::unordered_map<int, std::shared_ptr<Item>> items;
    std::ifstream file(filename);
    std::string line;

    if (file.is_open())
    {
        // skip header
        std::getline(file, line);

        while (std::getline(file, line))
        {
            std::shared_ptr<Item> item = parseCSVLine(line);

            items[item->getCode()] = item;
        }
    }

    return items;
}
