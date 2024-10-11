#ifndef FARM_H
#define FARM_H

#include <vector>
#include <string>
#include "Crop.h"
#include "Animal.h"
#include "Weather.h"
#include "Market.h"

class Farm {
public:
    Farm();  // Constructor

    void manageCrops();  // Method for managing crops
    void manageAnimals();  // Method for managing animals

    // Player's balance management
    float getBalance() const;  // Get player's current balance
    void addBalance(float amount);  // Add to player's balance
    void subtractBalance(float amount);  // Subtract from player's balance

    // Time and season management
    std::string getTime() const;  // Get current time/season as a string
    void advanceTime();  // Advance time, affects crops and animals

    // Check weather and market prices
    void checkWeather(Weather& weather) const;  // Display the current weather
    void checkMarketPrices(Market& market) const;  // Display current market pr

}