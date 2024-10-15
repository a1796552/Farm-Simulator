#ifndef MARKET_H
#define MARKET_H

#include <iostream>
#include <vector>
#include "Inventory.h"

class Market {
private:
    float cornPrice;
    float wheatPrice;

    void generateRandomPrices();  // Private helper function to generate random prices

public:
    Market();  // constructor

    // Function for buying seeds
    void buySeeds(const std::string& seedType, int quantity, float& balance, Inventory& inventory);

    // Function for updating the prices randomly for crops
    void updatePrices();

    // Function for selling produce (crops only)
    float sellProduce(float& playerBalance, Inventory& inventory);

    // Function for displaying current market prices
    void checkMarketPrices();
};

#endif  // MARKET_H
