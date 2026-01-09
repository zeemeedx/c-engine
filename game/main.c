#include "../src/engine/engine.h"
#include "../src/engine/config.h"
#include "../src/object/object.h"
#include "../src/graphics/sprite.h"
#include "../src/graphics/animator.h"

Sprite player_sprite;
Animator player_anim;

void player_create(GameObject* self) {
    self->position = (Vector2){400, 225};
    self->velocity = (Vector2){0, 0};
    self->rotation = 30.0f;
    self->active = 1;

    player_sprite = Sprite_Load(ASSET_PATH "player.png", 32, 32);
    Animator_Init(&player_anim, &player_sprite, 0.15f);

    self->animator = &player_anim;
}

void player_step(GameObject* self, float dt) {
    if (IsKeyDown(KEY_A)) self->position.x -= 200 * dt;
    if (IsKeyDown(KEY_D)) self->position.x += 200 * dt;
    if (IsKeyDown(KEY_W)) self->position.y -= 200 * dt;
    if (IsKeyDown(KEY_S)) self->position.y += 200 * dt;

    Animator_Update(self->animator, dt);
}

void player_draw(GameObject* self) {
    Animator_Draw(self->animator, self->position, self->rotation);
}

void player_destroy(GameObject* self) {
    Sprite_Unload(&player_sprite);
}

int main(void) {
    Engine_Init(800, 450, "C Engine");

    static GameObject player = {
        .on_create = player_create,
        .on_step = player_step,
        .on_draw = player_draw,
        .on_destroy = player_destroy
    };

    ObjectManager_Add(&player);

    while (!WindowShouldClose()) {
        Engine_Update();
        Engine_Draw();
    }

    Engine_Shutdown();
    return 0;
}
