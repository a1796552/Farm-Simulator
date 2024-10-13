#ifndef FARMASSET_H
#define FARMASSET_H

#include <string>

class FarmAsset {
protected:
    std::string name;  // Name of the asset (for both crops and animals)
    float value;       // Value of the asset (could represent market value or produce value)

public:
    // Constructor
    FarmAsset(std::string assetName, float assetValue)
        : name(assetName), value(assetValue) {}

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~FarmAsset() {}

    // Virtual method to be overridden by derived classes (for producing or growing)
    virtual void produce() = 0;

    // Getter for the name
    std::string getName() const { return name; }

    // Getter for the value
    float getValue() const { return value; }

    // Setter for the value
    void setValue(float newValue) { value = newValue; }
};

#endif
