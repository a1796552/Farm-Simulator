#include "Farm.h"
#include <iostream>

Farm::Farm() : day(1) { // Initialize day to 1
    balance = 1000.0f;  // Initialize balance
}

// Destructor to clean up dynamically allocated memory
Farm::~Farm() {
    for (auto asset : assets) {
        delete asset;  // Clean up each dynamically allocated asset
    }
}

void Farm::nextDay() {
    day++;
    std::cout << "Day " << day << " has started!\n";

    // Example: Each day crops grow, and animals produce goods
    plantCrops();  // Trigger crop growth (this can be changed depending on your game logic)
    feedAnimals(); // Trigger animal produce

    // You can add more logic here for daily events, weather changes, etc.
}

int Farm::getDay() const {
    return day;
}

// Implement the plantCrops() method with dynamic crop type
void Farm::plantCrops() {
    std::string cropType;
    std::cout << "Enter crop type (e.g., Corn, Wheat): ";
    std::cin >> cropType;

    float cropValue = 10.0f;  // You can adjust this based on crop type
    assets.push_back(new Crop(cropType, cropValue));  // Dynamically add crop
    std::cout << "Planted " << cropType << ".\n";
}

// Implement the feedAnimals() method with dynamic animal type
void Farm::feedAnimals() {
    std::string animalType;
    std::cout << "Enter animal type (e.g., Cow, Chicken): ";
    std::cin >> animalType;

    float animalValue = 50.0f;  // You can adjust this based on animal type
    assets.push_back(new Animal(animalType, animalValue));  // Dynamically add animal
    std::cout << "Added " << animalType << ".\n";
}

// Implement the harvestCrops() method
void Farm::harvestCrops() {
    for (auto& asset : assets) {
        Crop* crop = dynamic_cast<Crop*>(asset);
        if (crop && crop->getIsHarvestable()) {
            std::cout << "Harvested " << crop->getName() << " (" << crop->getCropType() << ").\n";
        }
    }
}

// Implement the collectProduce() method
void Farm::collectProduce() {
    for (auto& asset : assets) {
        Animal* animal = dynamic_cast<Animal*>(asset);
        if (animal && animal->getHealth() > 50) {
            std::cout << "Collected produce from " << animal->getName() << " (" << animal->getAnimalType() << ").\n";
        }
    }
}

// Implement the listAssets() method to display crops and animals on the farm
void Farm::listAssets() {
    if (assets.empty()) {
        std::cout << "No crops or animals on the farm.\n";
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