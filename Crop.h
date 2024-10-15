#ifndef CROP_H
#define CROP_H

#include "CropAsset.h"
#include <string>  // Include string for std::string

class Crop : public CropAsset {
public:
    Crop(std::string type, float value);  // Constructor declaration

    std::string getCropType() const;      // Getter for crop type
    void produce() override;              // Override produce method
};

#endif
