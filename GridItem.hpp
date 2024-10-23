#ifndef GRIDITEM_HPP
#define GRIDITEM_HPP

#include <iostream>
#include <utility>

class GridItem {
private:
    int x, y, width, height;
    static int activeGridItemCount; 

public:
    GridItem() : x(0), y(0), width(0), height(0) {
        activeGridItemCount++;
    }
    GridItem(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {
        activeGridItemCount++;
    }
    virtual ~GridItem() {
        activeGridItemCount--;
    }
    void setCoordinates(int newX, int newY) {
        x = newX;
        y = newY;
    }

    std::pair<int, int> getCoordinates() const {
        return {x, y};
    }

    int getGridWidth() const {
        return width;
    }

    int getGridHeight() const {
        return height;
    }

    static int getActiveGridItemCount() {
        return activeGridItemCount;
    }
};

int GridItem::activeGridItemCount = 0;

#endif 
