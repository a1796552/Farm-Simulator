#ifndef FARM_H
#define FARM_H

#include <vector>
#include <string>
#include "Crop.h"
#include "Animal.h"
#include "Market.h"
#include "FarmAsset.h"

class Farm {
private:
    std::vector<FarmAsset*> assets; // vector to hold both crops and animal vectors
    float balance;                  // player's balance or money
    int day;                        // tracking the day
    Inventory inventory;  
    

public:
    Farm();  // constructor to initialize balance and other data members

    void nextDay(Market& market);              // method to advance to next day
    int getDay() const;          // method to get the current day
    void plantCrops();           // method to plant crops
    void harvestCrops();         // method to harvest crops
    void feedAnimals();          // method to feed animals
    void collectProduce();       // method to collect produce from animals
    void listAssets();           // method to list all crops and animals on the farm
    
    void showInventory();        // display the inventory
    Inventory& getInventory();   // getter for inventory

    // destructor to clean up dynamically allocated memory
    ~Farm();
};

#endif