#ifndef MARKET_H
#define MARKET_H

#include <iostream>

class Market {
private:
    float cropPrice;
    float animalProducePrice;

    // updating the prices randomly for crops and animal produce
    void updatePrices();

public:
    Market();  // constructor

    // function for buying crops
    void buyCrops(float& playerBalance);

    // function for selling produce (either crops or animal produce)
    void sellProduce(float& playerBalance, int& harvestedCrops, int& animalProducts);

    // function for displaying current market prices
    void checkMarketPrices();
};

#endif  // MARKET_H
