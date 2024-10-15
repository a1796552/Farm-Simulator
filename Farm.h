#ifndef FARM_H
#define FARM_H

#include <vector>
#include <string>
#include "CropAsset.h"   // Include the new CropAsset class
#include "AnimalAsset.h"  // Include AnimalAsset class
#include "FarmAsset.h"    // Base class
#include "Market.h"

class Farm {
private:
    std::vector<FarmAsset*> assets;  // Vector to hold both CropAsset and AnimalAsset pointers
    float balance;
    int day;

public:
    Farm();
    void nextDay(Market& market);
    int getDay() const;
    void plantCrops();
    void feedAnimals();
    void harvestCrops();
    void collectProduce();
    void listAssets();
    ~Farm();
};

#endif
