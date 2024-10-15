#include "Crop.h"

// Implement the constructor
Crop::Crop(std::string type, float value)
    : FarmAsset(type, value), cropType(type), growthStage(0), isHarvestable(false) {}

// Implement the grow method
void Crop::grow() {
    growthStage++;
    if (growthStage >= 3) {
        isHarvestable = true;
    }
}

// Implement the produce method (calls grow)
void Crop::produce() {
    grow();
}

// Implement the getter for harvestable status
bool Crop::getIsHarvestable() const {
    return isHarvestable;
}

// Implement the getter for crop type
std::string Crop::getCropType() const {
    return cropType;
}
