#include "Inventory.h"
#include <iostream>

// Constructor
Inventory::Inventory() {
    // Optionally initialize with default items
}

// Add items to the inventory
void Inventory::addItem(const std::string& itemName, int quantity) {
    items[itemName] += quantity;  // Add quantity to the existing item or create a new one
}

// Remove items from the inventory
bool Inventory::removeItem(const std::string& itemName, int quantity) {
    if (items[itemName] >= quantity) {
        items[itemName] -= quantity;  // Deduct the quantity
        if (items[itemName] == 0) {
            items.erase(itemName);  // Remove the item if quantity becomes 0
        }
        return true;
    } else {
        std::cout << "Not enough " << itemName << " to remove.\n";
        return false;
    }
}

void Inventory::displayInventory() const {
    std::cout << "Inventory:\n";
    for (const auto& item : items) {
        std::cout << item.first << ": " << item.second << "\n";  // Display the item name and quantity
    }
}


// Check if an item exists and has enough quantity
bool Inventory::hasItem(const std::string& itemName, int quantity) const {
    return items.count(itemName) > 0 && items.at(itemName) >= quantity;
}

// Method to get the quantity of a specific item
int Inventory::getItem(const std::string& itemName) const {
    auto it = items.find(itemName);
    if (it != items.end()) {
        return it->second;  // Return the quantity if the item exists
    }
    return 0;  // Return 0 if the item doesn't exist
}