#pragma once

class Grid{
    public:
        Grid();
        void Initialize();
        int grid[20][10];
    private:
    int rowNum;
    int colNum;
    int cellSize;
};