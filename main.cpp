#include <raylib.h>
#include "game.h"

int main() {
    InitWindow(300,600, "Tetris");
    SetTargetFPS(60);
    
    

    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(DARKBLUE);
        grid.Draw();
        block.Draw();
        EndDrawing();
    }
    CloseWindow();
}
