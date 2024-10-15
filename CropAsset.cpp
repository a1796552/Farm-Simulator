#include "CropAsset.h"

// Constructor implementation
CropAsset::CropAsset(float value, std::string cropName, int maxGrowth)
    : FarmAsset(value, cropName), growthStage(0), maxGrowthStage(maxGrowth), isHarvestable(false) {}

// Increment the growth stage
void CropAsset::grow() {
    if (growthStage < maxGrowthStage) {
        growthStage++;
        if (growthStage >= maxGrowthStage) {  // Crop is harvestable if fully grown
            isHarvestable = true;
        }
    }
}

// Check if crop is harvestable
bool CropAsset::getIsHarvestable() const {
    return isHarvestable;
}

// Setter for growth stage
void CropAsset::setGrowthStage(int newGrowthStage) {
    growthStage = newGrowthStage;
}

// Get the current growth stage
int CropAsset::getGrowthStage() const {
    return growthStage;
}

// Get the maximum growth stage
int CropAsset::getMaxGrowthStage() const {
    return maxGrowthStage;
}
