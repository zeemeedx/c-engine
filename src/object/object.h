#ifndef OBJECT_H
#define OBJECT_H

#include "raylib.h"

typedef struct GameObject GameObject;

typedef void (*EventCreate)(GameObject*);
typedef void (*EventStep)(GameObject*, float dt);
typedef void (*EventDraw)(GameObject*);
typedef void (*EventDestroy)(GameObject*);

struct GameObject {
    Vector2 position;
    Vector2 velocity;
    int active;

    EventCreate on_create;
    EventStep on_step;
    EventDraw on_draw;
    EventDestroy on_destroy;
};

void ObjectManager_Init(void);
void ObjectManager_Add(GameObject* obj);
void ObjectManager_Update(float dt);
void ObjectManager_Draw(void);
void ObjectManager_Shutdown(void);

#endif