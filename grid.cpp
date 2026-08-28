#include "grid.h"
#include "block.h"

Grid::Grid(){
    rowNum = 20;
    colNum = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

// Initialises grid with zeros
void Grid::Initialize(){
    for (int row = 0; row < rowNum; row++){
        for (int column = 0; column < colNum; column++){
            grid[row][column] = 0;
        }
    }
}

std::vector<Color> Grid::GetCellColors(){
    return {DARKGRAY,GREEN,RED,ORANGE,YELLOW,PURPLE,SKYBLUE,BLUE};
}

// Draws grid
void Grid::Draw(){
    for (int row = 0;row<rowNum; row++){
        for (int column = 0; column < colNum; column++){
            int cellVal = grid[row][column];
            DrawRectangle(column * cellSize+1, row * cellSize+1,cellSize-1,cellSize-1,colors[cellVal]);
            
        }
    }
}

bool Grid::IsOutOfBounds(int row, int column){
    if (row >= 0 && row < rowNum && column >= 0 && column < colNum) {
        return false;
    }
    return true;
}