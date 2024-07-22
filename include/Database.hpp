#ifndef DATABASE_HPP_
#define DATABASE_HPP_

#include "../include/Item.hpp"
#include "../include/Inventory.hpp"
#include <string>
#include <vector>

class Database
{
public:
    /**
     * @brief Parametized Constructor
     *
     * Initializes a Database object.
     */
    Database(const std::string &filename);

    /**
     * @brief Save Inventory to CSV
     *
     * Saves the provided inventory of items to a CSV file.
     *
     * @param items Vector of pointers to Item objects
     * @param filename Name of the CSV file
     * @return true if the save operation was successful, otherwise false
     */
    bool saveToCSV(const Inventory &items, const std::string &filename) const;

    /**
     * @brief Load Inventory from CSV
     *
     * Loads items from a CSV file into a vector.
     *
     * @param filename Name of the CSV file
     * @return Vector of pointers to Item objects
     */
    std::unordered_map < int, std::shared_ptr<Item>> loadFromCSV(const std::string &filename) const;

private:
    /**
     * @brief Convert Item to CSV Format
     *
     * Converts an Item object to a CSV formatted string.
     *
     * @param item Pointer to the Item object
     * @return CSV formatted string
     */
    std::string itemToCSV(const std::shared_ptr<Item> item) const;

    /**
     * @brief Parse CSV Line to Item
     *
     * Parses a CSV formatted string to create an Item object.
     *
     * @param csvLine CSV formatted string
     * @return Pointer to the Item object
     */
    std::shared_ptr<Item> parseCSVLine(const std::string &csvLine) const;
};

#endif
