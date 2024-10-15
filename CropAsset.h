#ifndef CROPASSET_H
#define CROPASSET_H

#include "FarmAsset.h"
#include <string>  // Include string for std::string

class CropAsset : public FarmAsset {
protected:
    int growthStage;
    bool isHarvestable;

public:
    CropAsset(float value, std::string cropName)
        : FarmAsset(value, cropName), growthStage(0), isHarvestable(false) {}

    virtual void grow() {
        growthStage++;
        if (growthStage >= 3) {  // Example growth logic
            isHarvestable = true;
        }
    }

    virtual bool getIsHarvestable() const {
        return isHarvestable;
    }

    virtual void produce() override = 0;  // Pure virtual function to be overridden in derived classes
};

#endif
