#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x;
    int y;
};

std::vector<Point> findPossibleLocations(Point givenPoint, int distance) {
    std::vector<Point> possibleLocations;
    
    for (int i = givenPoint.x - distance; i <= givenPoint.x + distance; i++) {
        for (int j = givenPoint.y - distance; j <= givenPoint.y + distance; j++) {
            int manhattanDistance = std::abs(givenPoint.x - i) + std::abs(givenPoint.y - j);
            if (manhattanDistance == distance) {
                possibleLocations.push_back({i, j});
            }
        }
    }
    
    return possibleLocations;
}

int main() {
    Point givenPoint;
    int distance;
    
    std::cout << "Enter the coordinates of the given point (x y): ";
    std::cin >> givenPoint.x >> givenPoint.y;
    
    std::cout << "Enter the Manhattan distance: ";
    std::cin >> distance;
    
    std::vector<Point> possibleLocations = findPossibleLocations(givenPoint, distance);
    
    std::cout << "Possible locations:\n";
    for (const auto& location : possibleLocations) {
        std::cout << "(" << location.x << ", " << location.y << ")\n";
    }
    
    return 0;
}