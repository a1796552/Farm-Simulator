#ifndef INVENTORY_H
#define INVENTORY_H

#include <unordered_map>
#include <string>
#include <iostream>

class Inventory {
private:
    // Stores item names and their respective quantities
    std::unordered_map<std::string, int> items;

public:
    Inventory();  // Constructor

    // Method to add items to the inventory
    void addItem(const std::string& itemName, int quantity);

    // Method to remove items from the inventory
    bool removeItem(const std::string& itemName, int quantity);

    // Method to display the inventory
    void displayInventory() const;

    // Method to check if an item exists and has enough quantity
    bool hasItem(const std::string& itemName, int quantity) const;

    // Method to get the quantity of a specific item
    int getItem(const std::string& itemName) const;

    // Overloading the << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Inventory& inventory);

    // Overloading the >> operator for input
    friend std::istream& operator>>(std::istream& is, Inventory& inventory);
};

#endif  // INVENTORY_H
