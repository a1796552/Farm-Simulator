#ifndef ANIMAL_H
#define ANIMAL_H

#include "AnimalAsset.h"
#include <string>  // Include the string header for std::string

class Animal : public AnimalAsset {
public:
    Animal(std::string type, float value);  // Constructor with string and float parameters

    std::string getAnimalType() const;  // Getter for animal type
    void produce() override;  // Override produce method
};

#endif
