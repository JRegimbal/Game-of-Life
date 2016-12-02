#include "Board.h"
#include <thread>
#include <chrono>
#include <unistd.h>

int main(int argc, char **argv)
{
	int nflag = 0;
	int rflag = 0;
	char *nvalue = NULL;
	char *rvalue = NULL;
	int c;
	opterr = 0;

	while((c = getopt(argc, argv, "n:")) != -1)
		switch (c)
		{
			case 'n':
				nflag = 1;
				nvalue = optarg;
				break;
			case 'r':
				rflag = 1;
				rvalue = optarg;
				break;
			default:
				break;
		}
	
	using namespace std::this_thread;
	using namespace std::chrono;

	int x, y;
	x = y = (nflag == 1) ? atoi(nvalue) : 10;

	int ratio = (rflag == 1) ? atoi(rvalue) : 1;

	Board board(x, y, ratio);
	board.initializeBlocks();
	board.displayBoard();
	while(true)
	{
		board.clearBoard();
		board.displayBoard();
		//wait
		sleep_for(seconds(1));
		board.updateBlocks();
		if(board.noChange())
			break;
	}
	return 0;
}
