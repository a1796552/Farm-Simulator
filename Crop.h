#ifndef CROP_H
#define CROP_H

#include "FarmAsset.h"

class Crop : public FarmAsset {
private:
    std::string cropType;
    int growthStage;
    bool isHarvestable;

public:
    // Constructor declaration
    Crop(std::string type, float value);

    // Method declarations (no definitions here)
    void grow(); 
    void produce() override;
    bool getIsHarvestable() const;
    std::string getCropType() const;
};

#endif