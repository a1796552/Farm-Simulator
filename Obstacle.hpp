#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "Interactable.hpp"

class Obstacle : public Interactable {
public:
    Obstacle(int x, int y, int width, int height) : Interactable(x, y, width, height) {}

    void interact(Robot* player) override {
        player->takeHit();
        std::cout << "Hit obstacle! Robot health: " << player->getHealth() << std::endl;
    }

    InteractableType getType() const override {
        return OBSTACLE;
    }
};

#endif 

