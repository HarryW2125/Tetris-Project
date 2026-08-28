#pragma once
#include <vector>
#include <raylib.h>

class Grid{

    public:
        Grid();
        void Initialize();
        void Draw();
        int grid[20][10];

    private:
    int rowNum;
    int colNum;
    int cellSize;
    std::vector<Color> colors;
    std::vector<Color> GetCellColours();
};