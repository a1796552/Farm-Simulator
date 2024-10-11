#include "Farm.h"
#include <iostream>

// Constructor initializes the farm state
Farm::Farm() : balance(1000.0), currentSeason(0), currentDay(1) {
    // Optionally, you can add some default crops or animals here
}

// Manage crops by interacting with Crop objects
void Farm::manageCrops() {
    std::cout << "Managing crops...\n";
    // Logic to manage crops (e.g., planting, growing, harvesting)
}

// Manage animals by interacting with Animal objects
void Farm::manageAnimals() {
    std::cout << "Managing animals...\n";
    // Logic to manage animals (e.g., feeding, collecting produce)
}

// Get the current player's balance
float Farm::getBalance() const {
    return balance;
}

// Add to the player's balance
void Farm::addBalance(float amount) {
    balance += amount;
}

// Subtract from the player's balance
void Farm::subtractBalance(float amount) {
    balance -= amount;
}

// Get the current time/season as a string
std::string Farm::getTime() const {
    const std::string seasons[] = {"Spring", "Summer", "Fall", "Winter"};
    return "Day " + std::to_string(currentDay) + ", " + seasons[currentSeason];
}

// Advance time, affects crops and animals
void Farm::advanceTime() {
    currentDay++;
    if (currentDay > 30) {
        currentDay = 1;
        updateSeason();
    }
    // You can also add logic to update crop growth and animal productivity here
}

// Update the season when the day exceeds the current season's length
void Farm::updateSeason() {
    currentSeason = (currentSeason + 1) % 4;  // Loop through the seasons
    std::cout << "The season has changed to " << getTime() << "!\n";
}

// Check weather (calls Weather object)
void Farm::checkWeather(Weather& weather) const {
    std::cout << "Current Weather: " << weather.getCurrentWeather() << "\n";
}

// Check market prices (calls Market object)
void Farm::checkMarketPrices(Market& market) const {
