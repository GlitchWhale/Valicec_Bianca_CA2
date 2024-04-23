
#include "Bug.h"

bool Bug::isWayBlocked(Direction dir) {
    if (dir== North && position.second == 0) {
        return true;
    } else if (dir == East && position.first == 9) {
        return true;
    } else if (dir == South && position.second == 9) {
        return true;
    } else if (dir == West && position.first == 0) {
        return true;
    } else {
        return false;
    }
}