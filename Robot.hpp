#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "GridItem.hpp"

class Robot : public GridItem {
private:
    int health;

public:
    Robot(int gridWidth, int gridHeight) : GridItem(0, 0, gridWidth, gridHeight), health(3) {}

    int getHealth() const {
        return health;
    }

    void takeHit() {
        if (health > 0) {
            health--;
        }
    }

    bool move(int xOffset, int yOffset) {
        if ((xOffset != 0 && yOffset != 0) || (xOffset == 0 && yOffset == 0)) {
            return false;
        }

        int newX = getCoordinates().first + xOffset;
        int newY = getCoordinates().second + yOffset;

        if (newX >= 0 && newX < getGridWidth() && newY >= 0 && newY < getGridHeight()) {
            setCoordinates(newX, newY);
            return true;
        }

        return false;
    }
};

#endif
