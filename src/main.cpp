#include <iostream>
#include <cassert>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "../include/Inventory.hpp"
#include "../include/Item.hpp"
#include "../include/Database.hpp"

// void testAddItem()
// {
//     Inventory inventory;
//     Item item1("Item1", 10, 123, 10.0, 5.0); // quantity, code, price, initial cost
//     inventory.addItem(item1);

//     assert(inventory.getSize() == 10);     // Assuming `getSize` returns quantity
//     assert(inventory.getValue() == 100.0); // Assuming `getValue` returns total price

//     Item item2("Item2", 5, 456, 20.0, 10.0);
//     inventory.addItem(item2);

//     assert(inventory.getSize() == 15);     // Updated size after adding more items
//     assert(inventory.getValue() == 200.0); // Updated value after adding more items
//     std::cout << "testAddItem passed." << std::endl;
// }

// void testRemoveItem()
// {
//     Inventory inventory;
//     Item item1("Item1", 10, 123, 10.0, 5.0);
//     inventory.addItem(item1);

//     inventory.removeItem(item1);

//     assert(inventory.getSize() == 0);    // After removing, size should be 0
//     assert(inventory.getValue() == 0.0); // After removing, value should be 0.0
//     std::cout << "testRemoveItem passed." << std::endl;
// }

// void testCopyConstructor()
// {
//     Inventory original;
//     Item item1("Item1", 10, 123, 10.0, 5.0);
//     original.addItem(item1);

//     Inventory copy(original);
//     assert(copy.getSize() == original.getSize());
//     assert(copy.getValue() == original.getValue());
//     std::cout << "testCopyConstructor passed." << std::endl;
// }

// void testMoveConstructor()
// {
//     Inventory original;
//     Item item1("Item1", 10, 123, 10.0, 5.0);
//     original.addItem(item1);

//     Inventory moved(std::move(original));
//     assert(moved.getSize() == 10);     // Updated size after move
//     assert(moved.getValue() == 100.0); // Updated value after move
//     std::cout << "testMoveConstructor passed." << std::endl;
// }

// void runTests()
// {
//     testAddItem();
//     testRemoveItem();
//     testCopyConstructor();
//     testMoveConstructor();
// }

// int main()
// {
//     runTests();
//     std::cout << "All tests passed." << std::endl;
//     return 0;
// }

// Helper function to clear test data files
void clearTestFile(const std::string &filename)
{
    std::filesystem::remove(filename);
}

// Test for Database Constructor
void testDatabaseConstructor()
{
    // Create a Database instance
    Database db("test_products.csv");

    // Check if the file was created
    std::ifstream file("./data/test_products.csv");
    assert(file.good());
    file.close();

    // Clean up
    clearTestFile("./data/test_products.csv");
    std::cout << "testDatabaseConstructor passed." << std::endl;
}

// Test for saveToCSV
void testSaveToCSV()
{
    Database db("test_products.csv");

    Inventory inventory;
    auto item1 = Item("Item1", 5, 123, 10.0, 5.0);
    auto item2 = Item("Item2", 10, 456, 20.0, 10.0);
    inventory.addItem(item1);
    inventory.addItem(item2);

    bool result = db.saveToCSV(inventory, "./data/test_products.csv");
    assert(result == true); // Check if save operation was successful

    std::ifstream file("./data/test_products.csv");
    std::string line;

    // Check the header
    std::getline(file, line);
    assert(line == "Name,Code,Quantity,Price,PurchasePrice");

    // Check the first item
    std::getline(file, line);
    std::string expectedLine1 = item1.getName() + "," + std::to_string(item1.getCode()) + "," +
                                std::to_string(item1.getQuantity()) + "," + std::to_string(item1.getPrice()) + "," +
                                std::to_string(item1.getInitCost());
    assert(line == expectedLine1);

    // Check the second item
    std::getline(file, line);
    std::string expectedLine2 = item2.getName() + "," + std::to_string(item2.getCode()) + "," +
                                std::to_string(item2.getQuantity()) + "," + std::to_string(item2.getPrice()) + "," +
                                std::to_string(item2.getInitCost());
    assert(line == expectedLine2);

    file.close();
    // Clean up
    clearTestFile("./data/test_products.csv");
    std::cout << "testSaveToCSV passed." << std::endl;
}

// Test for loadFromCSV
void testLoadFromCSV()
{
    Database db("test_products.csv");

    std::ofstream file("./data/test_products.csv");
    file << "Name,Code,Quantity,Price,PurchasePrice\n";
    file << "Item1,123,5,10.0,5.0\n";
    file << "Item2,456,10,20.0,10.0\n";
    file.close();

    auto items = db.loadFromCSV("./data/test_products.csv");

    assert(items.size() == 2);
    assert(items[123]->getName() == "Item1");
    assert(items[456]->getName() == "Item2");

    // Clean up
    clearTestFile("./data/test_products.csv");
    std::cout << "testLoadFromCSV passed." << std::endl;
}

void runDatabaseTests()
{
    testDatabaseConstructor();
    testSaveToCSV();
    testLoadFromCSV();
}

int main()
{
    clearTestFile("./data/test_products.csv");
    runDatabaseTests();
    std::cout << "All tests passed." << std::endl;
    return 0;
}