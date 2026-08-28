#include "block.h"
#include <raylib.h>
Block::Block(){
    colors = GetCellColors();
    cellSize = 30;
    rotationState = 0;
    rowOffset = 0;
    columnOffset = 0;
};


std::vector<Color> Block::GetCellColors(){
    return {DARKGRAY,GREEN,RED,ORANGE,YELLOW,PURPLE,SKYBLUE,BLUE};
}

void Block::Draw(){
    std::vector<Position> tiles = GetCellPositions();
    for(Position tile: tiles){
        DrawRectangle(tile.column * cellSize +1, tile.row* cellSize +1, cellSize -1, cellSize -1, colors[id]);
    }

}

void Block::Move(int rows,int columns){
    rowOffset += rows;
    columnOffset += columns;
}

std::vector<Position> Block::GetCellPositions(){
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for(Position tile: tiles){
        Position newPos = Position(tile.row + rowOffset, tile.column + columnOffset);
        movedTiles.push_back(newPos);

    }
    return movedTiles;
}

void Block::Rotate(){
    rotationState ++;
    if (rotationState == (int)cells.size()){
        rotationState = 0;
    }
}