#include "object.h"
#include <stdlib.h>

#define MAX_OBJECTS 1024

static GameObject* objects[MAX_OBJECTS];
static int object_count = 0;

static void update_collider(GameObject* obj) {
    obj->collider.bounds = (Rectangle){
        obj->position.x,
        obj->position.y,
        obj->width_bbox,
        obj->height_bbox
    };
}

void ObjectManager_Init(void) {
    object_count = 0;
}

void ObjectManager_Add(GameObject* obj) {
    if (object_count >= MAX_OBJECTS) return; // Adicionar uma mensagem de erro no log futuramente

    objects[object_count++] = obj;

    if (obj->on_create)
        obj->on_create(obj);
}

void ObjectManager_Update(float dt) {
    for (int i = 0; i < object_count; i++) {
        GameObject* obj = objects[i];
        if (!obj->active) continue;

        if (obj->on_step)
            obj->on_step(obj, dt);

        update_collider(obj);
    }

    for (int i = 0; i < object_count; i++) {
        for (int j = i + 1; j < object_count; j++) { // Consertar essa ineficiência no futuro
            GameObject* a = objects[i];
            GameObject* b = objects[j];

            if (!a->active || !b->active) continue;

            if (CheckCollisionRecs(a->collider.bounds, b->collider.bounds)) {
                if (a->on_collision) a->on_collision(a, b);
                if (b->on_collision) b->on_collision(b, a);
            }
        }
    }
}

void ObjectManager_Draw(void) {
    for (int i = 0; i < object_count; i++) {
        GameObject* obj = objects[i];
        if (!obj->active) continue;

        if (obj->on_draw)
            obj->on_draw(obj);
    }   
}

void ObjectManager_Shutdown(void) {
    for (int i = 0; i < object_count; i++) {
        if (objects[i]->on_destroy)
            objects[i]->on_destroy(objects[i]);
    }   
}