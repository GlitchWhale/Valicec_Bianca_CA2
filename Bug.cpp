
#include "Bug.h"

bool Bug::isWayBlocked(Direction dir) {
    if (dir== North && position.second == 0) {
        return true;
    } else if (dir == East && position.first == size - 1) {
        return true;
    } else if (dir == South && position.second == size - 1) {
        return true;
    } else if (dir == West && position.first == 0) {
        return true;
    } else {
        return false;
    }
}