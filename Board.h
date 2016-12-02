#pragma once
#include "Block.h"
#define NEWLINES 15

class Board
{
	public:
		Board(int x_dim, int y_dim);
		~Board();
		void updateBlocks();
		void displayBoard();
		void clearBoard();
		void initializeBlocks();
	private:
		int sumNeighbors(int x, int y);
		int x_dim, y_dim;
		Block ** blockArray;
		char aliveChar = 'o';
		char deadChar = ' ';
};
