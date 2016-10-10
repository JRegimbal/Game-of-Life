#pragma once
#include "Block.h"

class Board
{
	public:
		Board(int x_dim, int y_dim);
		~Board();
		bool getBlockStatus(int x, int y);
		void updateBlocks();
		void displayBoard();
	protected:
		void setBlock(int x, int y, bool status);
	private:
		int x_dim, y_dim;
		Block ** blockArray;
		final char aliveChar = 'o';
		final char deadChar = ' ';
};
