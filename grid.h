#pragma once
#include <vector>
#include <raylib.h>

class Grid{

    public:
        Grid();
        void Initialize();
        void Draw();
        bool IsOutOfBounds(int row, int column);
        bool IsCellEmpty(int row, int column);
        int grid[20][10];

    private:
    bool IsRowComplete(int row);
    int rowNum;
    int colNum;
    int cellSize;
    std::vector<Color> colors;
    std::vector<Color> GetCellColors();
};