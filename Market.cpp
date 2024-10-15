#include "Market.h"
#include <cstdlib>
#include <ctime>
#include <vector>

// Constructor for Market
Market::Market() {
    srand(time(0));  // seed random number generator
    updatePrices();  // set initial prices for crops
}

// Update prices for crops
void Market::updatePrices() {
    cornPrice = rand() % 10 + 5;    // Price between $5 and $15
    wheatPrice = rand() % 8 + 3;    // Price between $3 and $10
}

// Check the market prices for the day
void Market::checkMarketPrices() {
    std::cout << "Current market prices:\n";
    std::cout << "Corn: $" << cornPrice << std::endl;
    std::cout << "Wheat: $" << wheatPrice << std::endl;
}

// Buying seeds
void Market::buySeeds(const std::string& seedType, int quantity, float& balance, Inventory& inventory) {
    float seedCost = 0.0f;

    // Determine the cost of the seed
    if (seedType == "Corn Seeds") {
        seedCost = 3.0f;
    } else if (seedType == "Wheat Seeds") {
        seedCost = 2.0f;
    }

    float totalCost = seedCost * quantity;

    // Check if player has enough balance
    if (balance >= totalCost) {
        balance -= totalCost;  // Deduct the cost from player's balance
        inventory.addItem(seedType, quantity);  // Add seeds to the inventory
        std::cout << "You bought " << quantity << " " << seedType << " for $" << totalCost << ".\n";
        std::cout << "Remaining balance: $" << balance << "\n";
    } else {
        std::cout << "You don't have enough money to buy " << quantity << " " << seedType << ".\n";
    }
}

// Selling crops
float Market::sellProduce(float& playerBalance, Inventory& inventory) {
    int cornQuantity = inventory.getItem("Corn");
    int wheatQuantity = inventory.getItem("Wheat");
    float totalEarned = (cornQuantity * cornPrice) + (wheatQuantity * wheatPrice);

    std::cout << "Sold " << cornQuantity << " Corn and " << wheatQuantity << " Wheat for $" << totalEarned << ".\n";
    playerBalance += totalEarned;
    std::cout << "Updated balance: $" << playerBalance << "\n";

    // Remove the sold items from inventory
    inventory.removeItem("Corn", cornQuantity);
    inventory.removeItem("Wheat", wheatQuantity);

    return playerBalance;
}
