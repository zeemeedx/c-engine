#include "engine.h"
#include "../object/object.h"

static float deltaTime = 0.0f;

void Engine_Init(int width, int height, const char* title) {
    InitWindow(width, height, title);
    SetTargetFPS(60);

    ObjectManager_Init();
}

void Engine_Update(void) {
    deltaTime = GetFrameTime();
    ObjectManager_Update(deltaTime);
}

void Engine_Draw(void) {
    BeginDrawing();
    ClearBackground(BLACK);

    ObjectManager_Draw();

    EndDrawing();
}

void Engine_Shutdown(void) {
    ObjectManager_Shutdown();
    CloseWindow();
}

float Engine_GetDeltaTime(void) {
    return deltaTime;
}