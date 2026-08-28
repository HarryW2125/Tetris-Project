#pragma once
#include "block.h"
#include "blocktypes.cpp"
#include "grid.h"
class Game 
{
    public:
    Game();
    Grid grid;
    bool gameOver;
    Block GetRandomBlock();
    void Draw();
    void HandleInp();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    private:
    std::vector<Block> blocks;
    std::vector<Block> GetAllBlocks();
    Block currentBlock;
    Block nextBlock;
    bool IsBlockOut();
    void RotateBlock();
    void LockCurrBlock();
    bool BlockFits();
    void resetGame();
};