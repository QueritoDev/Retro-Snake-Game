#include "game.h"
#include "food.h"
#include "gridConstants.h"
#include "snake.h"
#include <raylib.h>

void InitGame(Game& game){
    InitSnake(game.snake);
    InitFood(game.food);
    game.running = true;
}

void UpdateGame(Game& game){
    if(!game.running){
        if(IsKeyPressed(KEY_SPACE)){
            InitGame(game);
        }
        return;
    }
    UpdateSnake(game.snake, game.food);
    CheckCollisions(game);
}

void DrawGame(const Game& game){
    DrawSnake(game.snake);
    DrawFood(game.food);
    if(!game.running){
        DrawText("Press space to restart", 190, 700, 30, BLACK);
    }
}

void UnloadGame(const Game& game){
    UnloadFood(game.food);
}

void CheckCollisions(Game& game){
    Vector2 head = game.snake.body[0];

    if(head.x < 0 || head.x >= cellCount || head.y < 0 || head.y >= cellCount){
        game.running = false;
        return;
    }
}
