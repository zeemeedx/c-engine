#include "animator.h"

void Animator_Init(Animator* anim, Sprite* sprite, float frame_time) {
    anim->sprite = sprite;
    anim->current_frame = 0;
    anim->frame_time = frame_time;
    anim->timer = 0.0f;
}

void Animator_Update(Animator* anim, float dt) {
    anim->timer += dt;

    if (anim->timer >= anim->frame_time) {
        anim->timer = 0.0f;
        anim->current_frame = (anim->current_frame + 1) % anim->sprite->frame_count;
    }
}

void Animator_Draw(Animator* anim, Vector2 position, float rotation) {
    Rectangle src = {
        anim->current_frame * anim->sprite->frame_width,
        0,
        anim->sprite->frame_width,
        anim->sprite->frame_height
    };

    Rectangle dst = {
        position.x,
        position.y,
        anim->sprite->frame_width,
        anim->sprite->frame_height
    };

    DrawTexturePro(
        anim->sprite->texture,
        src,
        dst,
        (Vector2){0, 0},
        rotation,
        WHITE
    );
}