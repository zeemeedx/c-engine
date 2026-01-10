#ifndef COLLISION_H
#define COLLISION_H

#include "raylib.h"

typedef struct {
    Rectangle bounds;
} Collider;

int Collision_Check(Rectangle a, Rectangle b);

#endif