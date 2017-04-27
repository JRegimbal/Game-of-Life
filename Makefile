CC = g++
CFLAGS = --std=c++11 -g -Wall
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

EXECUTABLE = game-of-life

$(EXECUTABLE): $(OBJS)
	$(CC) -o $(EXECUTABLE) $(OBJS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE) $(OBJS)

partial_clean:
	rm $(OBJS)
