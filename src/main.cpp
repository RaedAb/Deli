#include <iostream>
#include <cassert>
#include "../include/Inventory.hpp"
#include "../include/Item.hpp"

void testAddItem()
{
    Inventory inventory;
    Item item1("Item1", 10, 123, 10.0, 5.0); // quantity, code, price, initial cost
    inventory.addItem(item1);

    assert(inventory.getSize() == 10);     // Assuming `getSize` returns quantity
    assert(inventory.getValue() == 100.0); // Assuming `getValue` returns total price

    Item item2("Item2", 5, 456, 20.0, 10.0);
    inventory.addItem(item2);

    assert(inventory.getSize() == 15);     // Updated size after adding more items
    assert(inventory.getValue() == 200.0); // Updated value after adding more items
    std::cout << "testAddItem passed." << std::endl;
}

void testRemoveItem()
{
    Inventory inventory;
    Item item1("Item1", 10, 123, 10.0, 5.0);
    inventory.addItem(item1);

    inventory.removeItem(item1);

    assert(inventory.getSize() == 0);    // After removing, size should be 0
    assert(inventory.getValue() == 0.0); // After removing, value should be 0.0
    std::cout << "testRemoveItem passed." << std::endl;
}

void testQueryDatabase()
{
    Inventory inventory;
    Item item1("Item1", 10, 123, 10.0, 5.0);
    inventory.addItem(item1);

    auto result = inventory.queryDatabase("123");
    assert(result != nullptr);
    assert(result->getCode() == 123);

    auto notFound = inventory.queryDatabase("999");
    assert(notFound == nullptr);
    std::cout << "testQueryDatabase passed." << std::endl;
}

void testCopyConstructor()
{
    Inventory original;
    Item item1("Item1", 10, 123, 10.0, 5.0);
    original.addItem(item1);

    Inventory copy(original);
    assert(copy.getSize() == original.getSize());
    assert(copy.getValue() == original.getValue());
    std::cout << "testCopyConstructor passed." << std::endl;
}

void testMoveConstructor()
{
    Inventory original;
    Item item1("Item1", 10, 123, 10.0, 5.0);
    original.addItem(item1);

    Inventory moved(std::move(original));
    assert(moved.getSize() == 10);     // Updated size after move
    assert(moved.getValue() == 100.0); // Updated value after move
    assert(original.getSize() == 0);   // Optional, depends on implementation
    std::cout << "testMoveConstructor passed." << std::endl;
}

void runTests()
{
    testAddItem();
    testRemoveItem();
    testQueryDatabase();
    testCopyConstructor();
    testMoveConstructor();
}

int main()
{
    runTests();
    std::cout << "All tests passed." << std::endl;
    return 0;
}
