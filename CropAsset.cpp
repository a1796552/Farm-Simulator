#include "CropAsset.h"

// constructor 
CropAsset::CropAsset(float value, std::string cropName, int maxGrowth)
    : FarmAsset(value, cropName), growthStage(0), maxGrowthStage(maxGrowth), isHarvestable(false) {}

// incrementing growth stage
void CropAsset::grow() {
    if (growthStage < maxGrowthStage) {
        growthStage++;
        if (growthStage >= maxGrowthStage) {  // Crop is harvestable if fully grown
            isHarvestable = true;
        }
    }
}

// check if crop can be harvested
bool CropAsset::getIsHarvestable() const {
    return isHarvestable;
}

// growth stage setter
void CropAsset::setGrowthStage(int newGrowthStage) {
    growthStage = newGrowthStage;
}

// retrieves growth stage
int CropAsset::getGrowthStage() const {
    return growthStage;
}

// returns max growth stage
int CropAsset::getMaxGrowthStage() const {
    return maxGrowthStage;
}
