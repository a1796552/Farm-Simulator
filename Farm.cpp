#include "Farm.h"
#include <iostream>

Farm::Farm() {
    // Initialize balance and other data members
    balance = 1000.0f;  // Starting balance for the player
}

// Implement the plantCrops() method
void Farm::plantCrops() {
    std::cout << "Planting crops...\n";
    // Placeholder logic for planting crops
    // You can add logic to add crops to the crops vector
}

// Implement the harvestCrops() method
void Farm::harvestCrops() {
    std::cout << "Harvesting crops...\n";
    // Placeholder logic for harvesting crops
}

// Implement the feedAnimals() method
void Farm::feedAnimals() {
    std::cout << "Feeding animals...\n";
    // Placeholder logic for feeding animals
}

// Implement the collectProduce() method
void Farm::collectProduce() {
    std::cout << "Collecting animal produce...\n";
    // Placeholder logic for collecting produce from animals
}