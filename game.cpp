#include "game.h"
#include <random>
Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
};

Block Game::GetRandomBlock(){
    if(blocks.empty()){
        blocks = GetAllBlocks();
    }
    int randInd = rand() % blocks.size();
    Block block = blocks[randInd];
    blocks.erase(blocks.begin() + randInd);
    return block;

}

std::vector<Block> Game::GetAllBlocks(){
    return {IBlock(),JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock()};
}

void Game::Draw(){
    grid.Draw();
    currentBlock.Draw();

}