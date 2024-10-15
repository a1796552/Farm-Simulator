#include "Animal.h"
#include <iostream>

// Implement the constructor
Animal::Animal(std::string type, float value)
    : FarmAsset(type, value), animalType(type), health(100), isProducing(false) {}

// Implement the feed method
void Animal::feed() {
    health += 10;
    if (health > 50) {
        isProducing = true;
    }
}

// Implement the produce method (checks if the animal is producing)
void Animal::produce() {
    if (isProducing) {
        std::cout << animalType << " is producing!\n";
    }
}

// Implement the getter for the animal's health
int Animal::getHealth() const {
    return health;
}

// Implement the getter for the animal type
std::string Animal::getAnimalType() const {
    return animalType;
}
