#ifndef GOAL_HPP
#define GOAL_HPP

#include "Interactable.hpp"
#include "Helper.hpp"
#include "Robot.hpp"

class Goal : public Interactable {
public:
    Goal(int x, int y, int width, int height) : Interactable(x, y, width, height) {}

    void interact(Robot* player) override {
        if (Helper::euclideanDistance(getCoordinates(), player->getCoordinates()) < 1.0) {
            std::cout << "Goal reached!" << std::endl;
        } else {
            std::cout << "Keep moving!" << std::endl;
        }
    }

    InteractableType getType() const override {
        return GOAL;
    }
};

#endif 
