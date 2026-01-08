#include "../src/engine/engine.h"
#include "../src/object/object.h"

void player_create(GameObject* self) {
    self->position = (Vector2){400, 225};
    self->velocity = (Vector2){0, 0};
    self->active = 1;
}

void player_step(GameObject* self, float dt) {
    if (IsKeyDown(KEY_A)) self->position.x -= 200 * dt;
    if (IsKeyDown(KEY_D)) self->position.x += 200 * dt;
    if (IsKeyDown(KEY_W)) self->position.y -= 200 * dt;
    if (IsKeyDown(KEY_S)) self->position.y += 200 * dt;
}

void player_draw(GameObject* self) {
    DrawCircleV(self->position, 20, RED);
}

int main(void) {
    Engine_Init(800, 450, "C Engine - Objects");

    static GameObject player = {
        .on_create = player_create,
        .on_step   = player_step,
        .on_draw   = player_draw
    };

    ObjectManager_Add(&player);

    while (!WindowShouldClose()) {
        Engine_Update();
        Engine_Draw();
    }

    Engine_Shutdown();
    return 0;
}
