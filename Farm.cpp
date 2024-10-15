#include "Farm.h"
#include "Crop.h"
#include "Animal.h"
#include "Market.h"
#include "Inventory.h"
#include <iostream>

Farm::Farm() : balance(1000.0f), day(1) {}

Farm::~Farm() {
    for (auto asset : assets) {
        delete asset;  // Clean up dynamically allocated assets
    }
}

void Farm::nextDay(Market& market) {
    day++;
    std::cout << "Day " << day << " has started!\n";

    market.updatePrices(); // Call market to update prices

    for (auto& asset : assets) {
        asset->produce();  // Polymorphic call to produce() for both crops and animals
    }
}

int Farm::getDay() const {
    return day;
}

// implement the plantCrops() method with dynamic crop type
void Farm::plantCrops() {
    std::string cropType;
    std::cout << "Enter crop type (e.g., Corn, Wheat): ";
    std::cin >> cropType;

    float cropValue = 10.0f;
    assets.push_back(new Crop(cropType, cropValue));  // Add as a CropAsset
    std::cout << "Planted " << cropType << ".\n";
}

void Farm::feedAnimals() {
    std::string animalType;
    std::cout << "Enter animal type (e.g., Cow, Chicken): ";
    std::cin >> animalType;

    float animalValue = 50.0f;
    assets.push_back(new Animal(animalType, animalValue));  // Add as an AnimalAsset
    std::cout << "Added " << animalType << ".\n";
}
  
void Farm::harvestCrops() {
    for (auto it = assets.begin(); it != assets.end();) {
        CropAsset* crop = dynamic_cast<CropAsset*>(*it);
        if (crop && crop->getIsHarvestable()) {
            std::cout << "Harvested " << crop->getName() << ".\n";
            delete crop;
            it = assets.erase(it);
        } else {
            ++it;
        }
    }
}

void Farm::collectProduce() {
    for (auto& asset : assets) {
        AnimalAsset* animal = dynamic_cast<AnimalAsset*>(asset);  // Correct cast
        if (animal && animal->getHealth() > 50 && animal->isProducingGoods()) {  // Check if producing goods
            std::cout << "Collected produce from " << animal->getName() << ".\n";
        }
    }
}

void Farm::listAssets() {
    if (assets.empty()) {
        std::cout << "No crops or animals on the farm.\n";
        inventory.displayInventory();
        return;
    }

    std::cout << "Listing all crops and animals on the farm:\n";
    for (auto& asset : assets) {
        CropAsset* crop = dynamic_cast<CropAsset*>(asset);
        if (crop) {
            std::cout << "Crop: " << crop->getName() << " (Growth Stage: " << crop->getIsHarvestable() << ")\n";
        }

        AnimalAsset* animal = dynamic_cast<AnimalAsset*>(asset);
        if (animal) {
            std::cout << "Animal: " << animal->getName() << " (Health: " << animal->getHealth() << ")\n";
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