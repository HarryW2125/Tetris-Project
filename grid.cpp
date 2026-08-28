#include "grid.h"

Grid::Grid(){
    rowNum = 20;
    colNum = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColours();
}

// Initialises grid with zeros
void Grid::Initialize(){
    for (int row = 0; row < rowNum; row++){
        for (int column = 0; column < colNum; column++){
            grid[row][column] = 0;
        }
    }
}

std::vector<Color> Grid::GetCellColours(){
    return {DARKGRAY,GREEN,RED,ORANGE,YELLOW,PURPLE,SKYBLUE,BLUE};
}

void Grid::Draw(){
    for (int row = 0;row<rowNum; row++){
        for (int column = 0; column < colNum; column++){
            int cellVal = grid[row][column];
            
        }
    }
}