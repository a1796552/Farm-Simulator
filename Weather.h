#ifndef WEATHER_H
#define WEATHER_H
// header guard
#include <string>
#include <vector>
#include <ctime>

class Weather {
public:
    Weather();
    std::string getCurrentWeather() const;
    void updateWeather(); // Calls this every minute to change weather

private:
    std::string currentWeather;
    std::vector<std::string> weatherConditions;
    void generateWeather(); //protects this information
};

#endif 
