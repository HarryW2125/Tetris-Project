#include <raylib.h>
#include "grid.h"
#include "blocktypes.cpp"

int main() {
    InitWindow(300,600, "Tetris");
    SetTargetFPS(60);
    Grid grid = Grid();
    TBlock block = TBlock();
    

    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(DARKBLUE);
        grid.Draw();
        block.Draw();
        EndDrawing();
    }
    CloseWindow();
}
