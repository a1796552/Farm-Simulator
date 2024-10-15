#ifndef FARMASSET_H
#define FARMASSET_H

#include <string>  // include the string header

class FarmAsset {
protected:
    float value;        // asset's value
    std::string name;   // asset's name

public:
    FarmAsset(float val, std::string assetName)
        : value(val), name(assetName) {}  // constructor initializes value and name

    virtual void produce() = 0;  // pure virtual function

    float getValue() const { return value; }
    std::string getName() const { return name; }

    virtual ~FarmAsset() {}
};

#endif
