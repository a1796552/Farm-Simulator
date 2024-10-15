#ifndef FARM_H
#define FARM_H

#include <vector>
#include <string>
#include "CropAsset.h"   // Include the new CropAsset class
#include "FarmAsset.h"    // Base class
#include "Market.h"

class Farm {
private:
    std::vector<FarmAsset*> assets; // vector to hold all farm assets (crops)
    float balance;                  // player's balance or money
    int day;                        // tracking the day
    Inventory inventory;            // inventory for managing seeds and produce
    
public:
    Farm();  // constructor to initialize balance and other data members

    void nextDay(Market& market);              // method to advance to next day
    int getDay() const;          // method to get the current day
    void plantCrops();           // method to plant crops
    void harvestCrops();         // method to harvest crops
    void listAssets();           // method to list all crops on the farm
    float& getBalance();         // getter method for balance
    void setBalance(float newBalance);
    void showInventory();        // display the inventory
    Inventory& getInventory();   // getter for inventory

    // destructor to clean up dynamically allocated memory
    ~Farm();
};

#endif
