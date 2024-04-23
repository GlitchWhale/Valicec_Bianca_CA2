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
            //set a new direction at random from 1 - 4
            direction = (rand() % 4 + 1);
        }
    }

    if (direction == 1) {
        if (!isWayBlocked(direction)) {
            position.second--;
        }
    } else if (direction == 2) {
        if (!isWayBlocked(direction)) {
            position.first++;
        }
    } else if (direction == 3) {
        if (!isWayBlocked(direction)) {
            position.second++;
        }
    } else if (direction == 4) {
        if (!isWayBlocked(direction)) {
            position.first--;
        }
    }

    path.push_back(position);
}



