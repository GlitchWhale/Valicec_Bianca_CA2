//
// Created by biava on 10/04/2024.
//
#include "Crawler.h"

void Crawler::move() {
//    A Crawler bug moves according to these rules:
//- moves by 1 unit in the direction it is currently facing
//- if at edge of board and can’t move in current direction (because
//its way is blocked), then, set a new direction at random. (Repeat
//until bug can move forward).-
//- record new position in the crawler's path history

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

