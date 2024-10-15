#include "Animal.h"
#include <iostream>

// Constructor definition
Animal::Animal(std::string type, float value)
    : AnimalAsset(value, type)  // Call the AnimalAsset constructor
{}

// Getter for animal type
std::string Animal::getAnimalType() const {
    return name;  // Assuming 'name' in the base class is the animal type
}

// Implementation of produce method
void Animal::produce() {
    std::cout << name << " is producing!\n";
}
