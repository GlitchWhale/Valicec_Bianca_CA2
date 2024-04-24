//
// Created by biava on 24/04/2024.
//

#include "Bishop.h"

void Bishop::move() {
    if (isWayBlocked(direction)) {
        while (isWayBlocked(direction)) {
            //set a new direction at random from 1 - 4
            direction = (rand() % 4 + 1);
        }
    }
    if (moveDiagonalUp) {
        if (direction == 1) {
            if (!isWayBlocked(direction)) {
                if(position.first == 0 || position.second == 0){
                    moveDiagonalUp = false;
                } else {
                    position.first--;
                    position.second--;
                }
            }
        } else if (direction == 2) {
            if (!isWayBlocked(direction)) {
                if(position.first == 9 || position.second == 0){
                    moveDiagonalUp = false;
                } else {
                    position.first++;
                    position.second--;
                }
            }
        } else if (direction == 3) {
            if (!isWayBlocked(direction)) {
                if(position.first == 9 || position.second == 9){
                    moveDiagonalUp = false;
                } else {
                    position.first++;
                    position.second++;
                }
            }
        } else if (direction == 4) {
            if (!isWayBlocked(direction)) {
                if(position.first == 0 || position.second == 9){
                    moveDiagonalUp = false;
                } else {
                    position.first--;
                    position.second++;
                }
            }
        }
    } else {
        if (direction == 1) {
            if (!isWayBlocked(direction)) {
                if (position.first == 0 || position.second == 9) {
                    moveDiagonalUp = true;
                } else {
                    position.first--;
                    position.second++;
                }
            }
        } else if (direction == 2) {
            if (!isWayBlocked(direction)) {
                if (position.first == 9 || position.second == 9) {
                    moveDiagonalUp = true;
                } else {
                    position.first++;
                    position.second++;
                }
            }
        } else if (direction == 3) {
            if (!isWayBlocked(direction)) {
                if (position.first == 9 || position.second == 0) {
                    moveDiagonalUp = true;
                } else {
                    position.first++;
                    position.second--;
                }
            }
        } else if (direction == 4) {
            if (!isWayBlocked(direction)) {
                if (position.first == 0 || position.second == 0) {
                    moveDiagonalUp = true;
                } else {
                    position.first--;
                    position.second--;
                }
            }
        }
    }

    path.push_back(position);
}