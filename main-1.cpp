#include <iostream>
#include "GridItem.hpp"
#include "Helper.hpp"

int main() {
    GridItem item1(1, 2, 10, 20);
    GridItem item2(4, 6, 5, 8);

    std::cout << "Item 1 coordinates: (" << item1.getCoordinates().first << ", " 
              << item1.getCoordinates().second << ")\n";
    std::cout << "Item 2 coordinates: (" << item2.getCoordinates().first << ", " 
              << item2.getCoordinates().second << ")\n";

    double distance = Helper::euclideanDistance(item1.getCoordinates(), item2.getCoordinates());
    std::cout << "Euclidean Distance between Item 1 and Item 2: " << distance << "\n";

    std::cout << "Active Grid Items: " << GridItem::getActiveGridItemCount() << "\n";

    return 0;
}
