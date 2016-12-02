#include "Board.h"
#include <thread>
#include <chrono>

int main()
{
	using namespace std::this_thread;
	using namespace std::chrono;

	int x=10, y=10;
	Board board(x, y);
	board.initializeBlocks();
	while(true)
	{
		board.displayBoard();
		//wait
		sleep_for(seconds(1));
		board.clearBoard();
		board.updateBlocks();
	}
	return 0;
}
