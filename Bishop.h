//
// Created by biava on 24/04/2024.
//

#ifndef CA2BIANCAVALICEC_BISHOP_H
#define CA2BIANCAVALICEC_BISHOP_H
#include "Bug.h"

class Bishop : public Bug {
private:
    bool moveDiagonalUp{};

public:
    Bishop(int id, pair<int, int> position, int direction, int size) {
        this->id = id;
        this->bugType = "Bishop";
        this->position = position;
        this->direction = direction;
        this->size = size;
        this->alive = true;
    }

    void move() override;

};
#endif //CA2BIANCAVALICEC_BISHOP_H
