#include <raylib.h>
#include "game.h"

int main() {
    InitWindow(300,600, "Tetris");
    SetTargetFPS(60);
    Game game = Game();
    

    while(WindowShouldClose() == false){
        game.HandleInp();
        BeginDrawing();
        ClearBackground(DARKBLUE);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}
