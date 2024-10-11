#include "Weather.h"
#include <cstdlib>
#include <ctime>

// Constructor
Weather::Weather() {
    // random number generator uses  the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // initialises the possible weather conditions
    weatherConditions = {"Sunny", "Rainy", "Cloudy", "Stormy", "Windy", "Foggy"};
    
    // generate the initial weather condition
    generateWeather();
}

// returns the current weather condition
std::string Weather::getCurrentWeather() const {
    return currentWeather;
}

// update the weather 
void Weather::updateWeather() {
    generateWeather();
}

// randomly select a weather condition
void Weather::generateWeather() {
    int randomIndex = std::rand() % weatherConditions.size();
    currentWeather = weatherConditions[randomIndex];
}
