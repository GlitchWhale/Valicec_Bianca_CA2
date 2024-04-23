
#include "Bug.h"

bool Bug::isWayBlocked(int dir) const {
    if (dir==1 && position.second == 0) {
        return true;
    } else if (dir==2 && position.first == 9) {
        return true;
    } else if (dir==3 && position.second == 9) {
        return true;
    } else if (dir==4 && position.first == 0) {
        return true;
    } else {
        return false;
    }
}

int Bug::getId() const {
    return id;
}

string Bug::getBugType() const {
    return bugType;
}

pair<int, int> Bug::getPosition() const {
    return position;
}

int Bug::getDirection() const {
    return direction;
}

int Bug::getSize() const {
    return size;
}

bool Bug::isAlive() const {
    return alive;
}

list<pair<int, int>> Bug::getPath() const {
    return path;
}