#include "Board.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>

Board::Board(int x_dim, int y_dim) : x_dim(x_dim), y_dim(y_dim)
{
    srand(time(NULL));
    blockArray = new Block*[x_dim];
    for(int i = 0; i < x_dim; i++)
    {
        blockArray[i] = new Block[y_dim];
    }
    ratio = 1;
    generation = 1;
}

Board::Board(int x_dim, int y_dim, int ratio) : x_dim(x_dim), y_dim(y_dim), ratio(ratio)
{
    srand(time(NULL));
    blockArray = new Block*[x_dim];
    for(int i = 0; i < x_dim; i++)
        blockArray[i] = new Block[y_dim];
    generation = 1;
}

Board::~Board()
{
    for(int i = 0; i < x_dim; i++)
    {
        delete [] blockArray[i];
    }
    delete [] blockArray;
}

void Board::initializeGosper()
{
    blockArray[1][6].setStatus(true);
    blockArray[1][7].setStatus(true);
    blockArray[2][6].setStatus(true);
    blockArray[2][7].setStatus(true);

    blockArray[11][6].setStatus(true);
    blockArray[11][7].setStatus(true);
    blockArray[11][8].setStatus(true);
    blockArray[12][5].setStatus(true);
    blockArray[12][9].setStatus(true);
    blockArray[13][4].setStatus(true);
    blockArray[13][10].setStatus(true);
    blockArray[14][4].setStatus(true);
    blockArray[14][10].setStatus(true);
    blockArray[15][7].setStatus(true);
    blockArray[16][5].setStatus(true);
    blockArray[16][9].setStatus(true);
    blockArray[17][6].setStatus(true);
    blockArray[17][7].setStatus(true);
    blockArray[17][8].setStatus(true);
    blockArray[18][7].setStatus(true);

    blockArray[21][4].setStatus(true);
    blockArray[21][5].setStatus(true);
    blockArray[21][6].setStatus(true);
    blockArray[22][4].setStatus(true);
    blockArray[22][5].setStatus(true);
    blockArray[22][6].setStatus(true);
    blockArray[23][3].setStatus(true);
    blockArray[23][7].setStatus(true);
    
    blockArray[25][2].setStatus(true);
    blockArray[25][3].setStatus(true);
    blockArray[25][7].setStatus(true);
    blockArray[25][8].setStatus(true);

    blockArray[35][4].setStatus(true);
    blockArray[35][5].setStatus(true);
    blockArray[36][4].setStatus(true);
    blockArray[36][5].setStatus(true);
}

void Board::initializeBlocks()
{
    using namespace std::this_thread;
    using namespace std::chrono;

    for(int i = 0; i < x_dim; i++)
    {
        for(int j = 0; j < y_dim; j++)
        {
            sleep_for(nanoseconds(10));
            blockArray[i][j].setStatus((rand() % (ratio+1)) > 0);
        }
    }
}

bool Board::noChange()
{
    return !changed;
}

void Board::updateBlocks()
{
    changed = false;
    for(int j = 0; j < y_dim; j++)
    {
        for(int i = 0; i < x_dim; i++)
        {
            int surroundings = sumNeighbors(i, j);
            if(blockArray[i][j].getStatus() && surroundings < 2)
            {
                blockArray[i][j].queueStatus(false);
                changed = true;
            }
            else if(blockArray[i][j].getStatus() && (surroundings == 2 || surroundings == 3))
            {
                blockArray[i][j].queueStatus(true);
            }
            else if(blockArray[i][j].getStatus() && surroundings > 3)
            {
                blockArray[i][j].queueStatus(false);
                changed = true;
            }
            else if(!blockArray[i][j].getStatus() && surroundings == 3)
            {
                blockArray[i][j].queueStatus(true);
                changed = true;
            }
        }
    }
    for(int j = 0; j < y_dim; j++)
    {
        for(int i = 0; i < x_dim; i++)
        {
            blockArray[i][j].updateStatus();
        }
    }
    generation++;
}

int Board::sumNeighbors(int x, int y)
{
    int sum = 0;
    for(int j = y-1; j <= y+1; j++)
    {
        for(int i = x-1; i <= x+1; i++)
        {
            sum += blockArray[(i+x_dim)%x_dim][(j+y_dim)%y_dim].getStatus() ? 1 : 0;    
        }
    }
    sum -= (int)blockArray[x][y].getStatus() ? 1 : 0;
    return sum;
}

void Board::displayBoard()
{
    for(int j = 0; j < y_dim; j++)
    {
        for(int i = 0; i < x_dim; i++)
        {
            std::cout << (blockArray[i][j].getStatus() ? aliveChar : deadChar);
        }
        std::cout << std::endl;
    }
    std::cout << generation;
}

void Board::clearBoard()
{
    for(int i = 0; i < y_dim; i++)
    {
        std::cout << "\e[A";
    }
    std::cout << '\r';
}


