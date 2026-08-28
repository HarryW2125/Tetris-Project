#include "game.h"
#include <random>
Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
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
    if(gameOver && keyPressed !=0){
        gameOver = false;
        resetGame();
    }
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
    if(!gameOver){
    currentBlock.Move(0,-1);
    if (IsBlockOut() || BlockFits() == false){
        currentBlock.Move(0,1);
    }}
}

void Game::MoveBlockRight(){
    if(!gameOver){
    currentBlock.Move(0,1);        
    if (IsBlockOut() || BlockFits() == false){
        currentBlock.Move(0,-1);
    }}
}

void Game::MoveBlockDown(){
    if(!gameOver){
    currentBlock.Move(1,0);
    if (IsBlockOut() || BlockFits() == false){
    currentBlock.Move(-1,0);
    LockCurrBlock();
    }}
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
    if (IsBlockOut() || BlockFits() == false){
        currentBlock.UndoRotate();
    }
}

void Game::LockCurrBlock(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position tile:tiles){
        grid.grid[tile.row][tile.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if(BlockFits() == false){
        gameOver = true;

    }
    nextBlock = GetRandomBlock();
    grid.CheckAllRows();
}


bool Game::BlockFits(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position tile:tiles){
        if (grid.IsCellEmpty(tile.row,tile.column) == false){
            return false;
        }
    } return true;
}

void Game::resetGame(){
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}