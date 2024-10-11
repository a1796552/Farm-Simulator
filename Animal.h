#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
public:
    Animal(std::string type, float health, bool producing);  // Constructor

    // Animal management methods
    void feed();  // Feed animal to increase health
    void collectProduce();  // Collect produce from the animal if it's producing
    bool isProducing() const;  // Check if the animal is producing
    void setProducing(bool producing);  // Set the producing status
    std::string getAnimalType() const;  // Get the type of animal
    float getHealth() const;  // Get the animal's health

    // Buy and sell methods
    float getProduceValue() const;  // Value of the animal's produce
    float getSellValue() const;  // Value of the animal when selling

private:
    std::string type;  // animals type
    float health;  // animal health
    bool producing;  // if animal is producing
    float produceValue;  // animal produce value
    float sellValue;  // animal sell value
};

#endif 
