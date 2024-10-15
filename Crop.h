#ifndef CROP_H
#define CROP_H

#include "CropAsset.h"
#include <string>

class Crop : public CropAsset {
public:
    Crop(std::string type, float value);  // Only declare the constructor here

    // Getter for crop type
    std::string getCropType() const;

    // Produce method implementation
    void produce() override;
};

#endif
