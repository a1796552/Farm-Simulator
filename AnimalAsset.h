#ifndef ANIMALASSET_H
#define ANIMALASSET_H

#include "FarmAsset.h"
#include <string>  // Include string for std::string

class AnimalAsset : public FarmAsset {
protected:
    int health;
    bool isProducing;

public:
    AnimalAsset(float value, std::string animalName)
        : FarmAsset(value, animalName), health(100), isProducing(false) {}

    virtual int getHealth() const { return health; }
    virtual bool isProducingGoods() const { return isProducing; }  // Add this method

    virtual void produce() override = 0;  // Virtual produce method to be overridden in derived classes
};

#endif

