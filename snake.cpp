#include "snake.h"
#include "customColors.h"
#include "food.h"
#include "gridConstants.h"
#include <raylib.h>
#include <raymath.h>

void InitSnake(Snake& snake){
    ResetSnake(snake);
}

void DrawSnake(const Snake& snake){
    for(unsigned int i = 0; i < snake.body.size(); i++){
        float x = snake.body[i].x;
        float y = snake.body[i].y;
        Rectangle segment = Rectangle {x * cellSize, y*cellSize, cellSize, cellSize};
        DrawRectangleRounded(segment, 0.5, 6, darkGreencustom);
    }
}

double lastUpdateTime = 0;

bool eventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

void UpdateSnake(Snake& snake, Food& food){
    CollisionWithFood(snake, food);

    if(eventTriggered(0.2)){
        snake.body.pop_back();
        snake.body.push_front(Vector2Add(snake.body[0], snake.direction));
    }

    if(IsKeyPressed(KEY_UP) && snake.direction.y !=1)
    {
        snake.direction = {0, -1};
    }
    if(IsKeyPressed(KEY_DOWN) && snake.direction.y != -1)
    {
        snake.direction = {0, 1};
    }
    if(IsKeyPressed(KEY_LEFT) && snake.direction.x != 1)
    {
        snake.direction = {-1, 0};
    }
    if(IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1)
    {
        snake.direction = {1,0};
    }
}


void CollisionWithFood(Snake& snake, Food& food){
    if(Vector2Equals(snake.body[0], food.position)){
        food.position = GenerateRandomPos();

        snake.body.push_front(Vector2Add(snake.body[0], snake.direction));
    }
}

void ResetSnake(Snake& snake){
    snake.body.clear();

    snake.body.push_back(Vector2{6,9});
    snake.body.push_back(Vector2{5,9});
    snake.body.push_back(Vector2{4,9});

    snake.direction = {1,0};
}
