#pragma once
#include <raylib.h>
#include "food.h"
#include <deque>

using namespace std;
struct Snake{
    deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
    Vector2 direction = {1,0};
};

void InitSnake(Snake& snake);
void UpdateSnake(Snake& snake, Food& food);
void CollisionWithFood(Snake& snake, Food& food);
void DrawSnake(const Snake& snake);
void ResetSnake(Snake& snake);
bool eventTriggered(double interval);
