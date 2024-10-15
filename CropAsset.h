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
    // Constructor with maxGrowth as a parameter
    CropAsset(float value, std::string cropName, int maxGrowth = 3);

    // Increment the growth stage
    virtual void grow();

    // Check if crop is harvestable
    virtual bool getIsHarvestable() const;

    // Setter for growth stage
    virtual void setGrowthStage(int newGrowthStage);

    // Get the current growth stage
    virtual int getGrowthStage() const;

    // Get the maximum growth stage
    virtual int getMaxGrowthStage() const;

    // Pure virtual function to be implemented by derived classes
    virtual void produce() override = 0;  // Derived classes should implement how they grow
};

#endif  // CROPASSET_H
