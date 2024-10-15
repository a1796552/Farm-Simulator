#ifndef FARM_H
#define FARM_H

#include <vector>
#include <string>
#include "Crop.h"
#include "Animal.h"
#include "FarmAsset.h"

class Farm {
private:
    std::vector<FarmAsset*> assets; // Vector to hold both crops and animal vectors
    float balance;                  // Player's balance or money
    int day;                        //tracking the day

public:
    Farm();  // Constructor to initialize balance and other data members

    void nextDay();              // Method to advance to next day
    int getDay() const;          // Method to get the current day
    void plantCrops();           // Method to plant crops
    void harvestCrops();         // Method to harvest crops
    void feedAnimals();          // Method to feed animals
    void collectProduce();       // Method to collect produce from animals
    void listAssets();           // Method to list all crops and animals on the farm

    // Destructor to clean up dynamically allocated memory
    ~Farm();
};

#endif