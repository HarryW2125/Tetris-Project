#include <raylib.h>
#include "game.h"
#include <iostream>

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
    InitWindow(500,620, "Tetris");
    SetTargetFPS(60);
    Game game = Game();
    

    while(WindowShouldClose() == false){
        game.HandleInp();
        DrawText("Score",360,10,30,BLACK);
        DrawText("Next",370,175,30,BLACK);
        if (game.gameOver == true){
            DrawText("Game Over!",320,450,30,BLACK);
            DrawText("Press any key to restart",300,500,20,BLACK);
        }
        DrawRectangle(320,55,170,60,SKYBLUE);

        char scoreText[10];
        sprintf(scoreText,"%d", game.score);
        DrawText(scoreText,380,70,30,BLACK);
        DrawRectangle(320,215,170,180,SKYBLUE);
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
