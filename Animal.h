#ifndef ANIMAL_H
#define ANIMAL_H

#include "FarmAsset.h"

class Animal : public FarmAsset {
private:
    std::string animalType;
    int health;
    bool isProducing;

public:
    // Constructor declaration
    Animal(std::string type, float value);

    // Method declarations (no definitions here)
    void feed();
    void produce() override;
    int getHealth() const;
    std::string getAnimalType() const;
};

#endif
