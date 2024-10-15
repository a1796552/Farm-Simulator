#ifndef CROPASSET_H
#define CROPASSET_H

#include "FarmAsset.h"
#include <string>  // Include string for std::string

class CropAsset : public FarmAsset {
protected:
    int growthStage;
    int maxGrowthStage;  // Max stage when the crop is fully grown
    bool isHarvestable;

public:
    CropAsset(float value, std::string cropName, int maxGrowth = 3)  // Added maxGrowth as a parameter
        : FarmAsset(value, cropName), growthStage(0), maxGrowthStage(maxGrowth), isHarvestable(false) {}

    // Increment the growth stage
    virtual void grow() {
        if (growthStage < maxGrowthStage) {
            growthStage++;
            if (growthStage >= maxGrowthStage) {  // Crop is harvestable if fully grown
                isHarvestable = true;
            }
        }
    }

    // Check if crop is harvestable
    virtual bool getIsHarvestable() const {
        return isHarvestable;
    }

    // Get the current growth stage
    virtual int getGrowthStage() const {
        return growthStage;
    }

    // Get the maximum growth stage
    virtual int getMaxGrowthStage() const {
        return maxGrowthStage;
    }

    // Pure virtual function to be implemented by derived classes
    virtual void produce() override = 0;  // Derived classes should implement how they grow
};

#endif

