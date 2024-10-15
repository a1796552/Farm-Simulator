#ifndef FARMASSET_H
#define FARMASSET_H

#include <string>  // Include the string header

class FarmAsset {
protected:
    float value;        // Asset's value
    std::string name;   // Asset's name

public:
    FarmAsset(float val, std::string assetName)
        : value(val), name(assetName) {}  // Constructor initializes value and name

    virtual void produce() = 0;  // Pure virtual function

    float getValue() const { return value; }
    std::string getName() const { return name; }

    virtual ~FarmAsset() {}
};

#endif
