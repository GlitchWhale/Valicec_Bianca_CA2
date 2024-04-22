//
// Created by biava on 10/04/2024.
//
#include "Hopper.h"

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

    for (int i = 0; i < hopLength; i++) {
        if (isWayBlocked(direction)) {
            while (isWayBlocked(direction)) {
                direction = static_cast<Direction>(rand() % 4);
            }
        }

        if (direction == North) {
            position.second--;
        } else if (direction == East) {
            position.first++;
        } else if (direction == South) {
            position.second++;
        } else if (direction == West) {
            position.first--;
        }

        path.push_back(position);
    }


}

