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

// returns all colours in grid
std::vector<Color> Grid::GetCellColors(){
    return {DARKGRAY,GREEN,RED,ORANGE,YELLOW,PURPLE,SKYBLUE,BLUE};
}

// Draws grid
void Grid::Draw(){

    for (int row = 0;row<rowNum; row++){

        for (int column = 0; column < colNum; column++){
            int cellVal = grid[row][column];
            DrawRectangle(column * cellSize+11, row * cellSize+11,cellSize-1,cellSize-1,colors[cellVal]);
            
        }
    }
}

// checks if an object is out of bounds
bool Grid::IsOutOfBounds(int row, int column){

    if (row >= 0 && row < rowNum && column >= 0 && column < colNum) {
        return false;
    }
    return true;
}

// checks if cell is empty
bool Grid:: IsCellEmpty(int row, int column){

    if(grid[row][column]== 0) {
        return true;
    }
        return false;
}


// checks if a row is full for line clearing purposes
bool Grid::IsRowComplete(int row){

    for (int column = 0; column <colNum;column++) {

        if (grid[row][column] == 0){
            return false;
        }

    } return true;
}

// clears a row
void Grid::ClearRow(int row){

    for (int column = 0; column <colNum;column++) {
        grid[row][column] = 0;
    }
    
}

// shifts a row down when line cleared
void Grid::ShiftRow(int row, int numOfRows){

        for (int column = 0; column <colNum;column++) {
        grid[row+numOfRows][column] = grid[row][column];
        grid[row][column] = 0;
    }

}

// checks if rows are complete, clears and shifts when needed
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