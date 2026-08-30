#pragma once
#include <vector>
#include <raylib.h>

class Grid{

    public:
        Grid();
        int grid[20][10];

        void Initialize();
        void Draw();
        bool IsOutOfBounds(int row, int column);
        bool IsCellEmpty(int row, int column);
        int CheckAllRows();

    private:
        int rowNum;
        int colNum;
        int cellSize;
        std::vector<Color> colors;
        std::vector<Color> GetCellColors();

        bool IsRowComplete(int row);
        void ClearRow(int row);
        void ShiftRow(int row, int numOfRows);
};