#include "Farm.h"
#include "Crop.h"
#include "Market.h"
#include "Inventory.h"
#include <fstream>
#include <iostream>

Farm::Farm() : balance(50.0f), day(1) {}

Farm::~Farm() {
    for (auto asset : assets) {
        delete asset;  // cleans dynamically allocated assets
    }
}

void Farm::nextDay(Market& market) {
    day++;
    std::cout << "Day " << day << " has started!\n";

    market.updatePrices();  // call market to update prices

    // call produce() for all assets
    for (auto& asset : assets) {
        asset->produce();  // calls crop::produce for crops to grow them
    }
}

int Farm::getDay() const {
    return day;
}

// implement the plantCrops method with dynamic crop type
void Farm::plantCrops() {
    std::string cropType;
    std::cout << "Enter crop type to plant (Wheat or Corn): ";
    std::cin >> cropType;

    if (inventory.hasItem(cropType + " Seeds", 1)) {  // check if the player has seeds
        inventory.removeItem(cropType + " Seeds", 1);  // use one seed from the inventory
        assets.push_back(new Crop(cropType, 10.0f));  // plant crops
        std::cout << "Planted " << cropType << ".\n";
    } else {
        std::cout << "You do not have any " << cropType << " seeds.\n";
    }
}

void Farm::harvestCrops() {
    for (auto it = assets.begin(); it != assets.end();) {
        Crop* crop = dynamic_cast<Crop*>(*it);
        if (crop && crop->getIsHarvestable()) {  // check if the crop is ready for harvest
            std::cout << "Harvested " << crop->getName() << ".\n";
            
            // add harvested crop to the inventory 
            inventory.addItem(crop->getName(), 1);  // add 1 of the harvested crop to the inventory
            
            // remove the harvested crop from the farm
            delete crop;  // free the memory
            it = assets.erase(it);  // remove from assets list and update the iterator
        } else {
            ++it;
        }
    }
}

// getter for player's balance
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

// save game state to a file
void Farm::saveGame(const std::string& filename) {
    std::ofstream file(filename);
    
    if (!file) {
        std::cerr << "Error opening file for saving!\n";
        return;
    }

    // save basic game info
    file << day << "\n";
    file << balance << "\n";

    // save inventory
    file << inventory;  
    
    // save assets
    for (auto& asset : assets) {
        Crop* crop = dynamic_cast<Crop*>(asset);
        if (crop) {
            file << crop->getName() << " " << crop->getGrowthStage() << "\n";
        }
    }

    file.close();
    std::cout << "Game saved successfully to " << filename << "\n";
}

// load game state from a file
void Farm::loadGame(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Error opening file for loading!\n";
        return;
    }

    // clear current state
    for (auto asset : assets) {
        delete asset;
    }
    assets.clear();

    // load basic game info
    file >> day;
    file >> balance;

    // Load inventory
    file >> inventory;  

    // load assets 
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
