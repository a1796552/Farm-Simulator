#include "Crop.h"
#include <iostream>

// Constructor definition
Crop::Crop(std::string type, float value)
    : CropAsset(value, type)  // Call CropAsset constructor
{}

// Getter for crop type
std::string Crop::getCropType() const {
    return name;  // Assuming 'name' in the base class is the crop type
}

// Produce method implementation
void Crop::produce() {
    grow();  // Example: crops "produce" by growing
    std::cout << name << " has grown.\n";
}
