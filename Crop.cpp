#include "Crop.h"
#include <iostream>

// Constructor definition (only in the .cpp file, not the header)
Crop::Crop(std::string type, float value)
    : CropAsset(value, type, 5)  // Set maxGrowthStage to 5 for crops
{}

// Getter for crop type
std::string Crop::getCropType() const {
    return name;  // Assuming 'name' in the base class is the crop type
}

// Produce method implementation (simulates the crop growing each day)
void Crop::produce() {
    grow();  // Calls the inherited grow() method to increment the growth stage
    std::cout << name << " has grown to stage " << getGrowthStage() << ".\n";
}
