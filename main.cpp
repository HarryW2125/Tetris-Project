#include <raylib.h>
#include "game.h"

double lastUpdate = 0;

bool TimedEventTriggered(double interval){
    double currentTime = GetTime();
    if (currentTime - lastUpdate >= interval){
        lastUpdate = currentTime;
        return true;
    }
    return false;
}

int main() {
    InitWindow(300,600, "Tetris");
    SetTargetFPS(60);
    Game game = Game();
    

    while(WindowShouldClose() == false){
        game.HandleInp();
        if (TimedEventTriggered(0.2)){
            game.MoveBlockDown();

        }
        BeginDrawing();
        ClearBackground(DARKBLUE);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}
