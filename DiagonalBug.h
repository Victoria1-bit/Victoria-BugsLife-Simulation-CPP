#ifndef DIAGONALBUG_H
#define DIAGONALBUG_H

#include "Bug.h"

class DiagonalBug : public Bug {
public:
    DiagonalBug(int id, int x, int y, Direction dir, int health);

    void move() override;
    void display() const override;
};

#endif