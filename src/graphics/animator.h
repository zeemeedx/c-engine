#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "sprite.h"

typedef struct {
    Sprite* sprite;
    int current_frame;
    float frame_time;
    float timer;
} Animator;

void Animator_Init(Animator* anim, Sprite* sprite, float frame_time);
void Animator_Update(Animator* anim, float dt);
void Animator_Draw(Animator* anim, Vector2 position, float rotation);

#endif