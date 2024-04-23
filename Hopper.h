//
// Created by biava on 10/04/2024.
//

#ifndef CA2BIANCAVALICEC_HOPPER_H
#define CA2BIANCAVALICEC_HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;

public:
    Hopper(int id, pair<int, int> position, int direction, int size, int hopLength) {
        this->id = id;
        this->bugType = "Hopper";
        this->position = position;
        this->direction = direction;
        this->size = size;
        this->alive = true;
        this->hopLength = hopLength;
    }

    [[nodiscard]] int getHopLength() const;

    void move() override;
};

#endif //CA2BIANCAVALICEC_HOPPER_H
