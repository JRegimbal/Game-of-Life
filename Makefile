CC = g++
CFLAGS = --std=c++11 -g -Wall
SRCS = Game-of-Life.cpp Block.cpp Board.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

EXECUTABLE = Game-of-Life.out

all: game-of-life

game-of-life: $(OBJS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS) 

Game-of-Life.o: Game-of-Life.cpp

Board.o: Board.cpp Board.h

Block.o: Block.cpp Block.h

clean:
	rm $(EXECUTABLE) $(OBJECTS)

partial_clean:
	rm $(OBJECTS)
