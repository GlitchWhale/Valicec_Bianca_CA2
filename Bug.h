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

protected:
    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;

public:
    virtual void move() = 0;

    virtual bool isWayBlocked(Direction dir) = 0;
};
#endif //CA2BIANCAVALICEC_BUG_H
