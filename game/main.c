#include "../src/engine/engine.h"
#include "../src/engine/config.h"
#include "../src/object/object.h"
#include "../src/graphics/sprite.h"
#include "../src/graphics/animator.h"

Sprite player_sprite;
Animator player_anim;

// Create Events
void player_create(GameObject* self) {
    self->position = (Vector2){400, 225};
    self->velocity = (Vector2){0, 0};
    self->rotation = 0.0f;
    self->active = 1;

    player_sprite = Sprite_Load(ASSET_PATH "player.png", 32, 32);
    Animator_Init(&player_anim, &player_sprite, 0.15f);

    self->width_bbox = 32;
    self->height_bbox = 32;

    self->animator = &player_anim;
}

// Step Events
void player_step(GameObject* self, float dt) {
    if (IsKeyDown(KEY_A)) self->position.x -= 200 * dt;
    if (IsKeyDown(KEY_D)) self->position.x += 200 * dt;
    if (IsKeyDown(KEY_W)) self->position.y -= 200 * dt;
    if (IsKeyDown(KEY_S)) self->position.y += 200 * dt;

    Animator_Update(self->animator, dt);
}

// Draw Events
void player_draw(GameObject* self) {
    Animator_Draw(self->animator, self->position, self->rotation);
}

void wall_draw(GameObject* self) {
    DrawRectangleRec(self->collider.bounds, GRAY);
}

// Destroy Events
void player_destroy(GameObject* self) {
    Sprite_Unload(&player_sprite);
}

// Collision Events
void player_collision(GameObject* self, GameObject* other) {
    self->position.x -= self->velocity.x;
    self->position.y -= self->velocity.y;
}

int main(void) {
    Engine_Init(1280, 720, "C Engine");

    static GameObject player = {
        .on_create = player_create,
        .on_step = player_step,
        .on_draw = player_draw,
        .on_destroy = player_destroy,
        .on_collision = player_collision
    };

    static GameObject wall = {
        .position = {500, 200},
        .width_bbox = 50,
        .height_bbox = 100,
        .active = 1,
        .on_draw = wall_draw
    };

    ObjectManager_Add(&player);
    ObjectManager_Add(&wall);

    while (!WindowShouldClose()) {
        Engine_Update();
        Engine_Draw();
    }

    Engine_Shutdown();
    return 0;
}
