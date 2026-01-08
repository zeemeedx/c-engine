#include "object.h"
#include <stdlib.h>

#define MAX_OBJECTS 1024

static GameObject* objects[MAX_OBJECTS];
static int object_count = 0;

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