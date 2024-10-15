#include "Farm.h"
#include "Crop.h"
#include "Market.h"
#include "Inventory.h"
#include <fstream>
#include <iostream>

Farm::Farm() : balance(50.0f), day(1) {}

Farm::~Farm() {
    for (auto asset : assets) {
        delete asset;  // Clean up dynamically allocated assets
    }
}

void Farm::nextDay(Market& market) {
    day++;
    std::cout << "Day " << day << " has started!\n";

    market.updatePrices();  // Call market to update prices

    // Call produce() for all assets (crops only now)
    for (auto& asset : assets) {
        asset->produce();  // This will call Crop::produce() for crops, which grows them
    }
}

int Farm::getDay() const {
    return day;
}

// implement the plantCrops() method with dynamic crop type
void Farm::plantCrops() {
    std::string cropType;
    std::cout << "Enter crop type to plant (Wheat or Corn): ";
    std::cin >> cropType;

    if (inventory.hasItem(cropType + " Seeds", 1)) {  // Check if the player has the seeds
        inventory.removeItem(cropType + " Seeds", 1);  // Use one seed from the inventory
        assets.push_back(new Crop(cropType, 10.0f));  // Plant the crop
        std::cout << "Planted " << cropType << ".\n";
    } else {
        std::cout << "You do not have any " << cropType << " seeds.\n";
    }
}

void Farm::harvestCrops() {
    for (auto it = assets.begin(); it != assets.end();) {
        Crop* crop = dynamic_cast<Crop*>(*it);
        if (crop && crop->getIsHarvestable()) {  // Check if the crop is ready for harvest
            std::cout << "Harvested " << crop->getName() << ".\n";
            
            // Add the harvested crop to the inventory (e.g., as "Wheat" or "Corn")
            inventory.addItem(crop->getName(), 1);  // Add 1 of the harvested crop to the inventory
            
            // Remove the harvested crop from the farm
            delete crop;  // Free the memory
            it = assets.erase(it);  // Remove from assets list and update the iterator
        } else {
            ++it;
        }
    }
}

// Getter for player's balance
float& Farm::getBalance() {
    return balance;
}

void Farm::setBalance(float newBalance) {
    balance = newBalance;
}

void Farm::listAssets() {
    if (assets.empty()) {
        std::cout << "No crops on the farm.\n";
        return;
    }

    std::cout << "Listing all crops on the farm:\n";
    for (auto& asset : assets) {
        Crop* crop = dynamic_cast<Crop*>(asset);
        if (crop) {
            std::cout << "Crop: " << crop->getName() << " (Growth Stage: " << crop->getGrowthStage() << ")\n";
        }
    }
}

// displaying inventory
void Farm::showInventory() {
    inventory.displayInventory();
}

Inventory& Farm::getInventory() {
    return inventory;  // return the inventory object
}

// Save game state to a file
void Farm::saveGame(const std::string& filename) {
    std::ofstream file(filename);
    
    if (!file) {
        std::cerr << "Error opening file for saving!\n";
        return;
    }

    // Save basic game info
    file << day << "\n";
    file << balance << "\n";

    // Save inventory
    file << inventory;  // Assuming you have an overloaded operator<< for Inventory

    // Save assets (crops)
    for (auto& asset : assets) {
        Crop* crop = dynamic_cast<Crop*>(asset);
        if (crop) {
            file << crop->getName() << " " << crop->getGrowthStage() << "\n";
        }
    }

    file.close();
    std::cout << "Game saved successfully to " << filename << "\n";
}

// Load game state from a file
void Farm::loadGame(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Error opening file for loading!\n";
        return;
    }

    // Clear current state
    for (auto asset : assets) {
        delete asset;
    }
    assets.clear();

    // Load basic game info
    file >> day;
    file >> balance;

    // Load inventory
    file >> inventory;  // Assuming you have an overloaded operator>> for Inventory

    // Load assets (crops)
    std::string cropName;
    int growthStage;
    while (file >> cropName >> growthStage) {
        Crop* crop = new Crop(cropName, 10.0f);
        crop->setGrowthStage(growthStage);
        assets.push_back(crop);
    }

    file.close();
    std::cout << "Game loaded successfully from " << filename << "\n";
}
