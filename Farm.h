#ifndef FARM_H
#define FARM_H

#include <vector>
#include <string>
// #include "Crop.h"
// #include "Animal.h"

class Farm {
private:
    // std::vector<Crop> crops;     // Vector to hold crop objects
    // std::vector<Animal> animals; // Vector to hold animal objects
    float balance;               // Player's balance or money

public:
    Farm();  // Constructor to initialize balance and other data members

    // Method declarations
    void plantCrops();           // Method to plant crops
    void harvestCrops();         // Method to harvest crops
    void feedAnimals();          // Method to feed animals
    void collectProduce();       // Method to collect produce from animals

    // Other methods can be added later
};

#endif