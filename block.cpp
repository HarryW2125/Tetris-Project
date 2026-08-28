#include "block.h"
#include <raylib.h>
Block::Block(){
    colors = GetCellColors();
    cellSize = 30;
    rotationState = 0;
};


std::vector<Color> Block::GetCellColors(){
    return {DARKGRAY,GREEN,RED,ORANGE,YELLOW,PURPLE,SKYBLUE,BLUE};
}

void Block::Draw(){
    std::vector<Position> tiles = cells[rotationState];
    for(Position tile: tiles){
        DrawRectangle(tile.column * cellSize +1, tile.row* cellSize +1, cellSize -1, cellSize -1, colors[id]);
    }

}