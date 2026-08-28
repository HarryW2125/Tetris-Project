#pragma one
#include "block.cpp"
#include "blocktypes.cpp"
#include "grid.h"
class Game 
{
    public:
    Game();
    Grid grid;
    Block GetRandomBlock();
    void Draw();
    private:
    std::vector<Block> blocks;
    std::vector<Block> GetAllBlocks();
    Block currentBlock;
    Block nextBlock;
};