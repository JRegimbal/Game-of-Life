#include "Board.h"
#include <iostream>

Board::Board(int x_dim, int y_dim) : x_dim(x_dim), y_dim(y_dim)
{
	blockArray = new Block[x_dim][y_dim];
}

Board::~Board()
{
	delete [] blockArray;
}

bool Board::getBlockStatus(int x, int y)
{
	return blockArray[x][y].getStatus();
}

void setBlock(int x, int y, bool status)
{
	blockArray[x][y].setStatus(status);
}

void Board::updateBlocks()
{
}

void Board::displayBoard()
{
	for(int j = 0; j < y_dim; j++)
	{
		for(int i = 0; i < x_dim; i++)
		{
			std::cout << blockArray[i][j].getStatus ? aliveChar : deadChar;
		}
		std::cout << std::endl;
	}
}
