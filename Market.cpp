#include "Market.h"
#include <cstdlib>  // for rand()
#include <ctime>    // for time()

// constructor
Market::Market() {
    srand(time(0));  // seed random number generator
    updatePrices();  // for setting initial prices when the Market object is created
}

// for randomly updating prices for crops and animal produce
void Market::updatePrices() {
    cropPrice = (rand() % 21) + 10;  // random price between 10 and 30
    animalProducePrice = (rand() % 16) + 5;  // random price between 5 and 20
}

// function for buying crops
void Market::buyCrops(float& playerBalance) {
    int quantity;
    std::cout << "Current crop price: $" << cropPrice << std::endl;
    std::cout << "How many crops would you like to buy? ";
    std::cin >> quantity;

    float totalCost = cropPrice * quantity;

    if (playerBalance >= totalCost) {
        playerBalance -= totalCost;
        std::cout << "You bought " << quantity << " crops for $" << totalCost << ". Your new balance is $" << playerBalance << ".\n";
    } else {
        std::cout << "You don't have enough money to buy that many crops!\n";
    }
}

// function for selling crops or animal produce
void Market::sellProduce(float& playerBalance, int& harvestedCrops, int& animalProducts) {
    char choice;
    std::cout << "What would you like to sell? (c: crops, a: animal produce): ";
    std::cin >> choice;

    if (choice == 'c' && harvestedCrops > 0) {
        std::cout << "You have " << harvestedCrops << " harvested crops.\n";
        playerBalance += harvestedCrops * cropPrice;
        std::cout << "You sold " << harvestedCrops << " crops for $" << harvestedCrops * cropPrice << ".\n";
        harvestedCrops = 0;  // Reset harvested crops after selling
    } else if (choice == 'a' && animalProducts > 0) {
        std::cout << "You have " << animalProducts << " animal products.\n";
        playerBalance += animalProducts * animalProducePrice;
        std::cout << "You sold " << animalProducts << " animal products for $" << animalProducts * animalProducePrice << ".\n";
        animalProducts = 0;  // Reset animal products after selling
    } else {
        std::cout << "You either chose an invalid option or don't have any produce to sell.\n";
    }
}

// function for displaying market prices
void Market::checkMarketPrices() {
    std::cout << "Current market prices:\n";
    std::cout << "Crop Price: $" << cropPrice << std::endl;
    std::cout << "Animal Produce Price: $" << animalProducePrice << std::endl;
}
