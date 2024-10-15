#ifndef CROPASSET_H
#define CROPASSET_H

#include "FarmAsset.h"
#include <string> 

class CropAsset : public FarmAsset {
protected:
    int growthStage;
    int maxGrowthStage;  //sets maximum for crops to grow
    bool isHarvestable;

public:
    // constructor with maxGrowth as a parameter
    CropAsset(float value, std::string cropName, int maxGrowth = 3);

    // increments growth stage
    virtual void grow();

    // check if crop is harvestable
    virtual bool getIsHarvestable() const;

    // setter for growth stage
    virtual void setGrowthStage(int newGrowthStage);

    // get current growth stage
    virtual int getGrowthStage() const;

    // get maximum growth stage
    virtual int getMaxGrowthStage() const;

    // virtual function, used by derived classes
    virtual void produce() override = 0;  // derived classes implement how they grow
};

#endif  // CROPASSET_H
