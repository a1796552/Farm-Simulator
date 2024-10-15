#ifndef CROP_H
#define CROP_H

#include "CropAsset.h"
#include <string>

class Crop : public CropAsset {
public:
    Crop(std::string type, float value);  //constructor

    // crop type getter
    std::string getCropType() const;

    // implements produce growth 
    void produce() override;
};

#endif
