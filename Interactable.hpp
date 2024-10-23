#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP

#include "GridItem.hpp"

enum InteractableType {
    GOAL,
    OBSTACLE
};

class Interactable : public GridItem {
private:
    static int activeInteractableCount;

public:
    Interactable(int x, int y, int width, int height) : GridItem(x, y, width, height) {
        activeInteractableCount++;
    }

    Interactable() : GridItem(0, 0, 0, 0) {
        activeInteractableCount++;
    }

    virtual void interact(Robot* player) = 0;
    virtual InteractableType getType() const = 0;

    static int getActiveInteractableCount() {
        return activeInteractableCount;
    }

    virtual ~Interactable() {
        activeInteractableCount--;
    }
};

int Interactable::activeInteractableCount = 0;

#endif 
