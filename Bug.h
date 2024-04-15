//
// Created by biava on 10/04/2024.
//
#ifndef CA2BIANCAVALICEC_BUG_H
#define CA2BIANCAVALICEC_BUG_H

#include <utility>
#include <list>
#include <cstdlib>

using namespace std;

enum Direction {
    North, East, South, West
};

class Bug {

public:
    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;

    virtual void move() = 0;

    bool isWayBlocked(Direction dir) {
        if (dir == North) {
            if (position.second == 0) {
                return true;
            }
        }
        if (dir == East) {
            if (position.first == size - 1) {
                return true;
            }
        }
        if (dir == South) {
            if (position.second == size - 1) {
                return true;
            }
        }
        if (dir == West) {
            if (position.first == 0) {
                return true;
            }
        }
    }
};
#endif //CA2BIANCAVALICEC_BUG_H
