#include "sprite.h"

Sprite Sprite_Load(const char* path, int frame_width, int frame_height) {
    Sprite sprite = {0};
    sprite.texture = LoadTexture(path);
    sprite.frame_width = frame_width;
    sprite.frame_height = frame_height;
    sprite.frame_count = sprite.texture.width / frame_width;

    return sprite;
}

void Sprite_Unload(Sprite* sprite) {
    UnloadTexture(sprite->texture);
}