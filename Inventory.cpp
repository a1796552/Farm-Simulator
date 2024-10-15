#include "Inventory.h"

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

// Display the current items in the inventory
void Inventory::displayInventory() const {
    std::cout << "Current Inventory:\n";
    if (items.empty()) {
        std::cout << "Inventory is empty.\n";
    } else {
        for (const auto& pair : items) {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
    }
}

// Check if an item exists and has enough quantity
bool Inventory::hasItem(const std::string& itemName, int quantity) const {
    return items.count(itemName) > 0 && items.at(itemName) >= quantity;
}
