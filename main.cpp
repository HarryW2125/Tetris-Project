#include <raylib.h>
#include "grid.h"

int main() {
    InitWindow(300,600, "Tetris");
    SetTargetFPS(60);
    Grid grid = Grid();

    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(DARKBLUE);
        grid.Draw();
        
        EndDrawing();
    }
    CloseWindow();
}
