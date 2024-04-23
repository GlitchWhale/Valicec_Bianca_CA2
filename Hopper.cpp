//
// Created by biava on 10/04/2024.
//
#include "Hopper.h"

int Hopper::getHopLength() const {
    return hopLength;
}


void Hopper::move() {
//A Hopper bug moves according to these rules:
//- moves by “hopLength” units in current direction
//- if at edge of board and can’t move/hop in current
//direction (as it is against an edge), then set a new
//direction at random. (repeat until bug can move
//forward) and then move.
//- if bug can’t move/hop the full ‘hopLength’, then the
//bug does move but ‘hits’ the edge and falls on the
//square where it hit the edge/wall
//- record new position in hoppers path history

    if (isWayBlocked(direction)) {
        while (isWayBlocked(direction)) {
            //set a new direction at random from 1 - 4
            direction = (rand() % 4 + 1);
        }
    }

    int distance = getHopLength();

    if (direction == 1) {
        for (int i = 0; i < distance; i++) {
            if (isWayBlocked(direction)) {
                break;
            }
            position.second--;
        }
    } else if (direction == 2) {
        for (int i = 0; i < distance; i++) {
            if (isWayBlocked(direction)) {
                break;
            }
            position.first++;
        }
    } else if (direction == 3) {
        for (int i = 0; i < distance; i++) {
            if (isWayBlocked(direction)) {
                break;
            }
            position.second++;
        }
    } else if (direction == 4) {
        for (int i = 0; i < distance; i++) {
            if (isWayBlocked(direction)) {
                break;
            }
            position.first--;
        }
    }

    path.push_back(position);
}