#include "Animal.h"
#include <iostream>

// Constructor 
Animal::Animal(std::string type, float health, bool producing)
    : type(type), health(health), producing(producing) {
    // Assign produce and sell values based on animal type
    if (type == "Cow") {
        produceValue = 15.0;  // milk val
        sellValue = 100.0;  // cow val
    } else if (type == "Chicken") {
        produceValue = 5.0;  // egg val
        sellValue = 20.0;  // chicken val
    } else if (type == "Sheep") {
        produceValue = 10.0;  // wool val
        sellValue = 50.0;  // sheep val
    }
}

// Feed animal to increase health
void Animal::feed() {
    if (health < 100.0) {
        health += 10.0;  // increase health by 10 each time fed
        if (health > 100.0) health = 100.0;  // Cap health at 100
        std::cout << type << " has been fed. Health is now " << health << ".\n";
    } else {
        std::cout << type << " is already at full health!\n";
    }
}

// Collect produce from the animal if it is producing
void Animal::collectProduce() {
    if (producing) {
        std::cout << "Collected produce from the " << type << ". Value: $" << produceValue << ".\n";
        producing = false;  // stop producing after collection
    } else {
        std::cout << "The " << type << " is not producing right now.\n";
    }
}

// Check if the animal is currently producing
bool Animal::isProducing() const {
    return producing;
}

// Set the producing status
void Animal::setProducing(bool producingStatus) {
    producing = producingStatus;
}

// Get the type of the animal
std::string Animal::getAnimalType() const {
    return type;
}

// Get the current health of the animal
float Animal::getHealth() const {
    return health;
}

// Get the value of the produce the animal produces
float Animal::getProduceValue() const {
    return produceValue;
}

// Get the value of the animal when selling
float Animal::getSellValue() const {
    return sellValue;
}
