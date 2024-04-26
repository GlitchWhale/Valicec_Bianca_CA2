//
// Created by biava on 10/04/2024.
//
#ifndef CA2BIANCAVALICEC_BUG_H
#define CA2BIANCAVALICEC_BUG_H

#include <utility>
#include <list>
#include <cstdlib>
#include <string>

using namespace std;

class Bug {

protected:
    int id;
    string bugType;
    pair<int, int> position;
    int direction;
    int size;
    bool alive;
    list<pair<int, int>> path;
    int killerId;

public:
    virtual void move() = 0;
    [[nodiscard]] bool isWayBlocked(int dir) const;
    [[nodiscard]] int getId() const;
    [[nodiscard]] string getBugType() const;
    [[nodiscard]] pair<int, int> getPosition() const;
    [[nodiscard]] int getDirection() const;
    [[nodiscard]] int getSize() const;
    [[nodiscard]] bool isAlive() const;
    [[nodiscard]] list<pair<int, int>> getPath() const;
    void setSize(int size);
    void setAlive(bool alive);
    void setKillerId(int killerId);
    [[nodiscard]] int getKillerId() const;
    list<pair<int, int>> getHistory();

};
#endif //CA2BIANCAVALICEC_BUG_H
