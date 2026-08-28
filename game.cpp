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

void Game::HandleInp(){
    int keyPressed = GetKeyPressed();
    switch(keyPressed){
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            break;
        case KEY_UP:
        RotateBlock();
        break;
    }
}

void Game::MoveBlockLeft(){
    currentBlock.Move(0,-1);
    if (IsBlockOut()){
        currentBlock.Move(0,1);
    }
}

void Game::MoveBlockRight(){
    currentBlock.Move(0,1);        
    if (IsBlockOut()){
        currentBlock.Move(0,-1);
    }
}

void Game::MoveBlockDown(){
    currentBlock.Move(1,0);
    if (IsBlockOut()){
    currentBlock.Move(-1,0);
    }
}

bool Game::IsBlockOut(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position tile:tiles){
        if (grid.IsOutOfBounds(tile.row,tile.column)){
            return true;
        }
    } return false;
}

void Game::RotateBlock(){
    currentBlock.Rotate();
}