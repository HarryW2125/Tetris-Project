#include "block.h"
#include <raylib.h>

//constructor
Block::Block(){
    colors = GetCellColors();
    cellSize = 30;
    rotationState = 0;
    rowOffset = 0;
    columnOffset = 0;
};

// draws blocks
void Block::Draw(int xOffset,int yOffset){
    std::vector<Position> tiles = GetCellPositions();

    for(Position tile: tiles){
        DrawRectangle(tile.column * cellSize + xOffset, tile.row* cellSize + yOffset, cellSize -1, cellSize -1, colors[id]);
    }

}

// moves block by an offset
void Block::Move(int rows,int columns){
    rowOffset += rows;
    columnOffset += columns;
}

//rotates
void Block::Rotate(){
    rotationState ++;

    //resets rotation if max rotation reached
    if (rotationState == (int)cells.size()){
        rotationState = 0;
    }
}

// reverses a rotate - decrements state
void Block::UndoRotate(){
    rotationState --;

    if (rotationState == -1){
        rotationState = cells.size() -1;
    }
}

// updates tile positions
std::vector<Position> Block::GetCellPositions(){
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;

    for(Position tile: tiles){
        Position newPos = Position(tile.row + rowOffset, tile.column + columnOffset);
        movedTiles.push_back(newPos);

    }

    return movedTiles;
}

// vector of colours used for blocks
std::vector<Color> Block::GetCellColors(){
    return {DARKGRAY,GREEN,RED,ORANGE,YELLOW,PURPLE,SKYBLUE,BLUE};
}
