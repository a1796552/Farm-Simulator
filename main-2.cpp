#include <iostream>
#include "Robot.hpp"
#include "Goal.hpp"
#include "Obstacle.hpp"
#include "Helper.hpp"

int main() {
    Robot player(15, 15);

    Goal goal(7, 7, 15, 15);
    Obstacle obstacle1(5, 5, 15, 15);
    Obstacle obstacle2(10, 10, 15, 15);

    std::cout << "Player starting position: (" << player.getCoordinates().first << ", " 
              << player.getCoordinates().second << ")\n";
    std::cout << "Player starting health: " << player.getHealth() << "\n";

    player.move(5, 0);
    player.move(0, 5);
    std::cout << "Moved to position: (" << player.getCoordinates().first << ", " 
              << player.getCoordinates().second << ")\n";
    obstacle1.interact(&player);  

    player.move(5, 0);
    player.move(0, 5);
    std::cout << "Moved to position: (" << player.getCoordinates().first << ", " 
              << player.getCoordinates().second << ")\n";
    obstacle2.interact(&player);

    std::cout << "Player health after hitting obstacles: " << player.getHealth() << "\n";

    player.move(-3, -3);
    goal.interact(&player); 

     if (!player.move(-5, 0)) {
        std::cout << "Invalid move! Player cannot move out of grid bounds.\n";
    }

     std::cout << "Final player position: (" << player.getCoordinates().first << ", " 
              << player.getCoordinates().second << ")\n";
    std::cout << "Active Grid Items: " << GridItem::getActiveGridItemCount() << "\n";
    std::cout << "Active Interactable Items: " << Interactable::getActiveInteractableCount() << "\n";

    return 0;
}
