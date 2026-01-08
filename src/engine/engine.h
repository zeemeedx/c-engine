#ifndef ENGINE_H
#define ENGINE_H

#include "raylib.h"

void Engine_Init(int width, int height, const char* title);
void Engine_Update(void);
void Engine_Draw(void);
void Engine_Shutdown(void);

float Engine_GetDeltaTime(void);

#endif