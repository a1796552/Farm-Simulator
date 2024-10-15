#include "Farm.h"
#include "Market.h"
#include "Inventory.h"
#include <iostream>

Farm::Farm() : day(1) { // initialize day to 1
    balance = 1000.0f;  // initialize balance
}

// destructor to clean up dynamically allocated memory
Farm::~Farm() {
    for (auto asset : assets) {
        delete asset;  // clean up each dynamically allocated asset
    }
}

void Farm::nextDay(Market& market) {
    day++;
    std::cout << "Day " << day << " has started!\n";
    market.updatePrices();  // randomly update market prices for the new day

    // each day crops grow, and animals produce goods
    plantCrops();  // trigger crop growth 
    feedAnimals(); // trigger animal produce
}

int Farm::getDay() const {
    return day;
}

// implement the plantCrops() method with dynamic crop type
void Farm::plantCrops() {
    std::string cropType;
    std::cout << "Enter crop type (e.g., Corn, Wheat): ";
    std::cin >> cropType;

    float cropValue = 10.0f;  // can adjust this based on crop type
    assets.push_back(new Crop(cropType, cropValue));  // dynamically add crop
    inventory.addItem(cropType, 5);
    std::cout << "Planted " << cropType << ".\n";
}

// implement the feedAnimals() method with dynamic animal type
void Farm::feedAnimals() {
    std::string animalType;
    std::cout << "Enter animal type (e.g., Cow, Chicken): ";
    std::cin >> animalType;

    float animalValue = 50.0f;  // can adjust this based on animal type
    assets.push_back(new Animal(animalType, animalValue));  // dynamically add animal
    std::cout << "Added " << animalType << ".\n";
}

// implement the harvestCrops() method
void Farm::harvestCrops() {
    for (auto& asset : assets) {
        Crop* crop = dynamic_cast<Crop*>(asset);
        if (crop && crop->getIsHarvestable()) {
            std::cout << "Harvested " << crop->getName() << " (" << crop->getCropType() << ").\n";
            inventory.addItem("Crops", 5);
        }
    }
}

// implement the collectProduce() method
void Farm::collectProduce() {
    for (auto& asset : assets) {
        Animal* animal = dynamic_cast<Animal*>(asset);
        if (animal && animal->getHealth() > 50) {
            std::cout << "Collected produce from " << animal->getName() << " (" << animal->getAnimalType() << ").\n";
            inventory.addItem("Animal Produce", 3);
        }
    }
}

// implement the listAssets() method to display crops and animals on the farm
void Farm::listAssets() {
    if (assets.empty()) {
        std::cout << "No crops or animals on the farm.\n";
        inventory.displayInventory();
        return;
    }

    std::cout << "Listing all crops and animals on the farm:\n";

    for (auto& asset : assets) {
        Crop* crop = dynamic_cast<Crop*>(asset);
        if (crop) {
            std::cout << "Crop: " << crop->getCropType() << " (Growth Stage: " << crop->getIsHarvestable() << ")\n";
        }

        Animal* animal = dynamic_cast<Animal*>(asset);
        if (animal) {
            std::cout << "Animal: " << animal->getAnimalType() << " (Health: " << animal->getHealth() << ")\n";
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
