#include "grid.h"

Grid::Grid(){
    rowNum = 20;
    colNum = 10;
    cellSize = 30;
    Initialize();
}

// Initialises grid with zeros
void Grid::Initialize(){
    for (int row = 0; row < rowNum; row++){
        for (int column = 0; column < colNum; column++){
            grid[row][column] = 0;
        }
    }
}