#ifndef HELPER_HPP
#define HELPER_HPP

#include <utility>
#include <cmath>

class Helper {
public:
    static double euclideanDistance(std::pair<int, int> item1, std::pair<int, int> item2) {
        int x1 = item1.first;
        int y1 = item1.second;
        int x2 = item2.first;
        int y2 = item2.second;
        return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    }
};

#endif 
