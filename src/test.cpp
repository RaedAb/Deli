/**
 * File to test the tiime it takes to create 1 million item objects as well as the time to save and load from csv.
 * Walmart has 120k items but ill do 1 million to be safe.
 * 
 * The results where:
 * Time to create and add 1 million items: 0.690617 seconds
 * Time to save 1 million items to CSV: 1.19766 seconds
 * Time to load 1 million items from CSV: 5.23395 seconds
 * 
 * The time could be improved upon but realistically no small bussiness will contain 1 million items
 * Saving to the CSV will only be done occasionally after a every transaction
 * And loading from CSV is meant to happen once at start up.
 * 
 * switching to an ordered map would let me preform binary search on the csv but
 * will sacrifice the insertion and deletion times which are realistically more frequent,
 * so for the moment Ill leave the setup as is
 * 
 * And once again 1 million items is alot for even walmart
*/

#include <iostream>
#include <chrono>
#include "../include/Inventory.hpp"
#include "../include/Database.hpp"

void testTimes() {
    Inventory warmart;

    auto start1 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++) {
        Item item("item" + std::to_string(i), 15, i, 2.50, 1.50);
        warmart.addItem(item);
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;

    std::cout << "Time to create and add 1 million items: " << elapsed1.count() << " seconds" << std::endl;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto start2 = std::chrono::high_resolution_clock::now();

    Database db("timetests.csv");
    db.saveToCSV(warmart, "./data/timetests.csv");

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;

    std::cout << "Time to save 1 million items to CSV: " << elapsed2.count() << " seconds" << std::endl;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto start3 = std::chrono::high_resolution_clock::now();

    // Correct the function call based on your actual function definition
    auto items = db.loadFromCSV("./data/timetests.csv");

    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed3 = end3 - start3;

    std::cout << "Time to load 1 million items from CSV: " << elapsed3.count() << " seconds" << std::endl;
}

// int main()
// {
//     testTimes();
//     return 0;
// }