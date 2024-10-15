#include "Crop.h"
#include <iostream>

// constructor definition 
Crop::Crop(std::string type, float value)
    : CropAsset(value, type, 5)  // Set maxGrowthStage to 5 for crops
{}

// crop type getter
std::string Crop::getCropType() const {
    return name;  // Assuming 'name' in the base class is the crop type
}

// getter for produce growth stage
void Crop::produce() {
    grow();  // Calls the inherited grow() method to increment the growth stage
    std::cout << name << " has grown to stage " << getGrowthStage() << ".\n";
}
