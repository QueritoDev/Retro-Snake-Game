#pragma once
#include <raylib.h>

struct Food{
    Vector2 position;
    Texture2D texture;
};

void InitFood(Food& food);
void DrawFood(const Food& food);
Vector2 GenerateRandomPos();
void UnloadFood(const Food& food);
