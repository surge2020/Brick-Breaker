CC = g++
CFLAGS = -Wall -lSDL2 -lSDL2_image -I./inc
all:
	$(CC) $(CFLAGS) -o run ./src/*.cpp