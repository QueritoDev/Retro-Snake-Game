#pragma once
#include "snake.h"
#include "food.h"
#include "gridConstants.h"

struct Game {
    Snake snake;
    Food food;
    bool running = true;
};

void InitGame(Game& game);
void UpdateGame(Game& game);
void DrawGame(const Game& game);
void CheckCollisions(Game& game);
void UnloadGame(const Game& game);


