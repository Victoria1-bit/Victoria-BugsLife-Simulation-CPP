//
// Created by Asake on 29/04/2026.
//

#ifndef HOPPER_H
#define HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;

public:
    Hopper(int id, int x, int y, Direction dir, int health, int hopLength);

    void move() override;
    void display() const override;
};

#endif