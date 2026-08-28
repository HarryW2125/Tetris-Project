#pragma once
#include "block.h"
#include "blocktypes.cpp"
#include "grid.h"
class Game 
{
    public:
    Game();
    Grid grid;
    Block GetRandomBlock();
    void Draw();
    void HandleInp();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    private:
    bool IsBlockOut();
    void RotateBlock();
    void LockCurrBlock();
    std::vector<Block> blocks;
    std::vector<Block> GetAllBlocks();
    Block currentBlock;
    Block nextBlock;
};