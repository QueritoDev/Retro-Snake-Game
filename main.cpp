#include <iostream>
#include <raylib.h>
#include "game.h"
#include "customColors.h"
#include "gridConstants.h"

using namespace std;

int main(void) {
    cout << "Starting the game..." << endl;

    InitWindow(screen_width, screen_height, "Retro Snake");
    SetTargetFPS(60);

    Game game;
    InitGame(game);
    while (!WindowShouldClose()) {
        UpdateGame(game);
        BeginDrawing();
        DrawFPS(0, 0);
        ClearBackground(greencustom);
        DrawGame(game);
        EndDrawing();
    }
    UnloadGame(game);
    CloseWindow();
    return 0;
}
