#pragma once
#include <vector>
#include <map>
#include "position.h"
#include <raylib.h>
class Block{
public:
    Block();
    int id;
    std::map<int,std::vector<Position>> cells;
    void Draw();
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();


private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    std::vector<Color> GetCellColors();
    int rowOffset;
    int columnOffset;
};