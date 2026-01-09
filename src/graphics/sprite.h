#ifndef SPRITES_H
#define SPRITES_H

#include "raylib.h"

typedef struct {
    Texture2D texture;
    int frame_width;
    int frame_height;
    int frame_count;
} Sprite;

Sprite Sprite_Load(const char* path, int frame_width, int frame_height);
void Sprite_Unload(Sprite* sprite);

#endif