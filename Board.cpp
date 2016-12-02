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
}

Board::Board(int x_dim, int y_dim, int ratio) : x_dim(x_dim), y_dim(y_dim), ratio(ratio)
{
	srand(time(NULL));
	blockArray = new Block*[x_dim];
	for(int i = 0; i < x_dim; i++)
		blockArray[i] = new Block[y_dim];
}

Board::~Board()
{
	for(int i = 0; i < x_dim; i++)
	{
		delete [] blockArray[i];
	}
	delete [] blockArray;
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
}

void Board::clearBoard()
{
	/*for(int i = 0; i < NEWLINES; i++)
	{
		std::cout << std::endl;
	}*/
	for(int i = 0; i < y_dim; i++)
	{
		std::cout << "\e[A";
	}
	std::cout << '\r';
}


