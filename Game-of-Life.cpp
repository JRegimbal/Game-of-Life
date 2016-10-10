#include "Board.h"


int main()
{
	int x=10, y=10;
	Board board(x, y);
	board.initializeBlocks();
	while(true)
	{
		board.displayBoard();
		board.updateBlocks();
		//wait
	}
	return 0;
