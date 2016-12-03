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
	int tflag = 0;
	int gflag = 0;
	char *tvalue = NULL;
	char *xvalue = NULL;
	char *yvalue = NULL;
	char *nvalue = NULL;
	char *rvalue = NULL;
	int c;
	opterr = 0;

	while((c = getopt(argc, argv, "gn:r:x:y:t:")) != -1)
		switch (c)
		{
			case 'g':
				gflag = 1;
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
			case 't':
				tflag = 1;
				tvalue = optarg;
				break;
			default:
				break;
		}
	
	using namespace std::this_thread;
	using namespace std::chrono;

	int x, y;
	x = y = (nflag == 1 && gflag == 0) ? atoi(nvalue) : (gflag == 1) ? 50 : 10;
	x = (xflag == 1 && gflag == 0) ? atoi(xvalue) : x;
	y = (yflag ==1 && gflag == 0) ? atoi(yvalue) : y;
	int ratio = (rflag == 1) ? atoi(rvalue) : 1;
	int delayMillis = (tflag == 1) ? atoi(tvalue) : 1000;
	Board board(x, y, ratio);
	if(gflag == 1)
	{
		x = y = 50;
		delayMillis = (tflag == 0) ? 100 : tflag;
		board.initializeGosper();
	}
	else
	{
		board.initializeBlocks();
	}
	board.displayBoard();
	while(true)
	{
		board.clearBoard();
		board.displayBoard();
		//wait
		sleep_for(milliseconds(delayMillis));
		board.updateBlocks();
		if(board.noChange())
			break;
	}
	return 0;
}
