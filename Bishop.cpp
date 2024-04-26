//
// Created by biava on 24/04/2024.
//

#include <ctime>
#include "Bishop.h"

void Bishop::move() {
    // Seed the random number generator
    srand(time(0));

    // Randomly choose a direction
    int randomDirection = rand() % 4 + 1; // Generate a random number between 1 and 4

    // Update the position based on the randomly chosen direction
    if (randomDirection == 1) {
        // Move diagonally up and left
        if (position.first > 0 && position.second > 0) {
            position.first--;
            position.second--;
        }
    } else if (randomDirection == 2) {
        // Move diagonally up and right
        if (position.first > 0 && position.second < 9) {
            position.first--;
            position.second++;
        }
    } else if (randomDirection == 3) {
        // Move diagonally down and right
        if (position.first < 9 && position.second < 9) {
            position.first++;
            position.second++;
        }
    } else if (randomDirection == 4) {
        // Move diagonally down and left
        if (position.first < 9 && position.second > 0) {
            position.first++;
            position.second--;
        }
    }

    // Add the new position to the path
    path.push_back(position);
}
