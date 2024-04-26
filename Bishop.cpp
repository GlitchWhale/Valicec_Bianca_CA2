//
// Created by biava on 24/04/2024.
//

#include "Bishop.h"

void Bishop::move() {
    // Check for edges
    if (position.first == 0 || position.second == 9) {
        moveDiagonalUp = true;
    } else if (position.first == 9 || position.second == 0) {
        moveDiagonalUp = false;
    }

    if (moveDiagonalUp) {
        // Move diagonally up
        if (direction == 1) {
            position.first--;
            position.second--;
        } else if (direction == 2) {
            position.first++;
            position.second--;
        } else if (direction == 3) {
            position.first++;
            position.second++;
        } else if (direction == 4) {
            position.first--;
            position.second++;
        }
    } else {
        // Move diagonally down
        if (direction == 1) {
            position.first--;
            position.second++;
        } else if (direction == 2) {
            position.first++;
            position.second++;
        } else if (direction == 3) {
            position.first++;
            position.second--;
        } else if (direction == 4) {
            position.first--;
            position.second--;
        }
    }

    path.push_back(position);
}