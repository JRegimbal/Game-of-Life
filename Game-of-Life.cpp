#include "Board.h"
#include <thread>
#include <chrono>
#include <unistd.h>

int main(int argc, char **argv)
{
	int nflag = 0;
	int rflag = 0;
	int xflag = 0;
	int yflag = 0;
	char *xvalue = NULL;
	char *yvalue = NULL;
	char *nvalue = NULL;
	char *rvalue = NULL;
	int c;
	opterr = 0;

	while((c = getopt(argc, argv, "n:r:x:y:")) != -1)
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
			case 'x':
				xflag = 1;
				xvalue = optarg;
				break;
			case 'y':
				yflag = 1;
				yvalue = optarg;
				break;
			default:
				break;
		}
	
	using namespace std::this_thread;
	using namespace std::chrono;

	int x, y;
	x = y = (nflag == 1) ? atoi(nvalue) : 10;
	x = (xflag == 1) ? atoi(xvalue) : x;
	y = (yflag ==1) ? atoi(yvalue) : y;
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
