CC=g++
CFLAGS=-std=c++14 -c -O3
OUTPUT = snake

all: snake

snake: main.o snake.o fruit.o game.o
	$(CC) main.o snake.o fruit.o game.o -o $(OUTPUT)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

snake.o: snake.cpp
	$(CC) $(CFLAGS) snake.cpp
	
fruit.o: fruit.cpp
	$(CC) $(CFLAGS) fruit.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp

clean:
	rm -rf *.o $(OUTPUT)
