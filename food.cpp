#include "food.h"
#include "gridConstants.h"
#include <raylib.h>


void InitFood(Food& food){
    Image image = LoadImage("Graphics/food.png");
    food.texture = LoadTextureFromImage(image);
    UnloadImage(image);
    food.position = GenerateRandomPos();
}

void DrawFood(const Food& food){
    DrawTexture(food.texture, food.position.x * cellSize, food.position.y * cellSize, WHITE);
}

Vector2 GenerateRandomPos(){
    float x = GetRandomValue(0, cellCount-1);
    float y = GetRandomValue(0, cellCount-1);
    return Vector2{x,y};
}

void UnloadFood(const Food& food){
    UnloadTexture(food.texture);
}
