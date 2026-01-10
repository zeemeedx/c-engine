#ifndef OBJECT_H
#define OBJECT_H

#include "raylib.h"
#include "../graphics/animator.h"
#include "../collision/collision.h"

typedef struct GameObject GameObject;

typedef void (*EventCreate)(GameObject*);
typedef void (*EventStep)(GameObject*, float dt);
typedef void (*EventDraw)(GameObject*);
typedef void (*EventDestroy)(GameObject*);
typedef void (*EventCollision)(struct GameObject*, struct GameObject*);

struct GameObject {
    Vector2 position;
    Vector2 velocity;
    float rotation;
    int active;

    Collider collider;
    float width_bbox;
    float height_bbox;

    Animator* animator;

    EventCreate on_create;
    EventStep on_step;
    EventDraw on_draw;
    EventDestroy on_destroy;
    EventCollision on_collision;
};

void ObjectManager_Init(void);
void ObjectManager_Add(GameObject* obj);
void ObjectManager_Update(float dt);
void ObjectManager_Draw(void);
void ObjectManager_Shutdown(void);

#endif