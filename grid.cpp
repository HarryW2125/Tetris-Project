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

bool Grid:: IsCellEmpty(int row, int column){
    if(grid[row][column]== 0) {
        return true;
    }
        return false;
}

bool Grid::IsRowComplete(int row){
    for (int column = 0; column <colNum;column++) {
        if (grid[row][column] == 0){
            return false;
        }

    } return true;
}

void Grid::ClearRow(int row){
    for (int column = 0; column <colNum;column++) {
        grid[row][column] == 0;
    }
    
}

void Grid::ShiftRow(int row, int numOfRows){
        for (int column = 0; column <colNum;column++) {
        grid[row+numOfRows][column] = grid[row][column];
        grid[row][column] = 0;
    }

}

int Grid::CheckAllRows(){
    int completeRows = 0;

    for(int row = rowNum -1; row>= 0; row--){
        if (IsRowComplete(row)) {
            ClearRow(row);
            completeRows ++;
        }
        else if (completeRows >0){
            ShiftRow(row, completeRows);
        }
    }

    return completeRows;
}